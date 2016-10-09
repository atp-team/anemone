# How to make Anemone Connector

Anemone Connector is a Ruby class which interconnect the [Anemone Platform](http://www.anemone.cloud) with other web services and REST APIs.

In this tutorial we will explain how Anemone Connectors work and how you can make your own.

> We maintain a [list of all available Anemone Connectors](https://github.com/ceskasporitelna/anemone/tree/master/connectors), feel free to take a look around and get some inspiration.

## How Anemone Connector works?

Anemone Connector is nothing else than a plain old ruby object (or class respectively).

It needs to live inside the `Connectors` module and it needs to inherit from the `Connectors::Base` class:

```ruby
module Connectors
  class MyCoolConnector < Base
    # ...
  end
end
```

It needs to define two public methods: `setup` and `call`.

```ruby
module Connectors
  class MyCoolConnector < Base
    class << self
      def setup
        # here you can perform setup of your connector if needed
      end

      # Takes 2 arguments: +input_variable_value+, and +API_KEY+
      def call(*args)
        self.setup # call() has to call setup()
        
        # ...
      end
    end
  end
end
```

The `call` method of your connector is called every time when the connector is invoked from an Anemone App.

> Connectors are invoked every time when their input variable doed change its value.

Lets now further explore how the code inside the `call` method should look like:

```ruby
# Takes 2 arguments: +input_variable_value+, and +API_KEY+
def call(*args)
  self.setup # call() has to call setup()
  	
  # process arguments
  input = args.fetch(0, 0) 	# value of input variable is at args[0]
  api_key = args[1] 		# API_KEY is at args[1]
  	
  # load output variables (they are passed as args[2])
  variables = args.fetch(2).fetch('variables').reduce(Hash.new) { 
    |hsh, var| hsh[var] = nil; hsh 
  }
  
  # perform connector computation ... which updates variables
  
  variables # return the updated variables
end
```

Example of a connector `MyCoolConnector` with an input variable `varInput` and two output variables `varFoo` and `varBar` which will load new values of the two variables from the api endpoint `https://some-api.com/resource` from the respective JSON properties `"foo"` and `"bar"` might look like this: 

```ruby
# Takes 2 arguments: +input_variable_value+, and +API_KEY+
def call(*args)
  self.setup # call() has to call setup()
  	
  # process arguments
  input = args.fetch(0, 0) 	# value of input variable is at args[0]
  api_key = args[1] 		# API_KEY is at args[1]
  	
  # load output variables (they are passed as args[2])
  variables = args.fetch(2).fetch('variables').reduce(Hash.new) { 
    |hsh, var| hsh[var] = nil; hsh 
  }
  
  # perform connector HTTP request
  response = HTTParty.get(
    'https://some-api.com/resource',
    headers: { 'API-KEY' => api_key }
  )
  
  # do not change variables if result was not HTTP 200 OK
  return variables if response.code != 200
  
  # parse response
  response = JSON.parse(response.body)
  
  # update variables with new values
  variables.each_key do |var|
    variables[var] = response['foo'] if var.match(/.*Foo/)
    variables[var] = response['bar'] if var.match(/.*Bar/)
  end
  
  variables # return the updated variables
end
```

The whole source code of this connector should look like this:

```ruby
require 'httparty'

module Connectors
  class MyCoolConnector < Base
    class << self
      def setup
        # here you can perform setup of your connector if needed
      end

      # Takes 2 arguments: +input_variable_value+, and +API_KEY+
      def call(*args)
        self.setup # call() has to call setup()
  	
        # process arguments
        input = args.fetch(0, 0) 	# value of input variable is at args[0]
        api_key = args[1] 		    # API_KEY is at args[1]
  	
        # load output variables (they are passed as args[2])
        variables = args.fetch(2).fetch('variables').reduce(Hash.new) { 
          |hsh, var| hsh[var] = nil; hsh 
        }
  
        # perform connector HTTP request
        response = HTTParty.get(
          'https://some-api.com/resource',
          headers: { 'API-KEY' => api_key }
        )
  
        # do not change variables if result was not HTTP 200 OK
        return variables if response.code != 200
  
        # parse response
        response = JSON.parse(response.body)
  
        # update variables with new values
        variables.each_key do |var|
          variables[var] = response['foo'] if var.match(/.*Foo/)
          variables[var] = response['bar'] if var.match(/.*Bar/)
        end
  
        variables # return the updated variables
      end
    end
  end
end
```

Such connector should have a following in it's documentation README file:

--

### Summary

| Name | Web Service | Input | Output |
|:---- |:--------:|:--------------------:|:---------------------:|
| myCoolConnector | [SomeAPI](https://some-api.com/resource/) | input: *string* | foo: *string*, bar: *string* |

### Authentication

[SomeAPI](https://some-api.com/resource/) API key is required for authentication.

### Usage

```json
"connectors": {
  "myCoolConnector": {
    "connector": "myCoolConnector",
    "variable": "varInput",
    "args": {
      "apiKey": "INSERT YOUR API KEY HERE"
    },
    "output": {
      "variables": [
        "varFoo",
        "varBar"
      ]
    }
  }
}
```
--

We can recommend using the Ruby [httparty gem](https://github.com/jnunemaker/httparty) for HTTP REST API calls. **It is awesome**.

> When you HTTParty, you must party hard! *-- httparty post install message*

### Real world example

We will conclude this tutorial by showing a real world example of simple *Anemone Cloud Connector* **exchangeRate**. Your find more information about this connector in the [list of all available Anemone Connectors](https://github.com/ceskasporitelna/anemone/tree/master/connectors).

```ruby
require 'httparty'

module Connectors
  class ExchangeRate < Base
    class << self
      def setup
        # noop
      end

      # Takes 2 arguments: +czk_cost+, and +API_KEY+
      def call(*args)
        self.setup
        
        # process arguments
        czk = args.fetch(0, 0)
        web_api_key = args[1]
        
        # load output variables
        variables = args.fetch(2).fetch('variables').reduce(Hash.new) { |hsh, var| hsh[var] = nil; hsh }
        
        # perform connector HTTP request
        response = HTTParty.get('https://api.csas.cz/sandbox/webapi/api/v1/exchangerates',
                                headers: { 'WEB-API-key' => web_api_key }
        )
        
        # do not change variables if result was not HTTP 200 OK
        return variables if response.code != 200
        
        # parse response
        response = JSON.parse(response.body)
        eur = response.find { |currency| currency['shortName'] == 'EUR' }
        usd = response.find { |currency| currency['shortName'] == 'USD' }
        
        # update variables with new values
        variables.each_key do |var|
          variables[var] = czk/eur['valMid'] if var.match(/.*Eur/)
          variables[var] = czk/usd['valMid'] if var.match(/.*Usd/)
        end
        
        variables # return the updated variables
      end
    end
  end
end
```

## How to create Anemone Connector?

In order to create your own Anemone Connector, you just need to implement the Ruby class based on the rules and conventions described above and submit it as a pull request to this repository.

We will review it and deploy to the Anemone Cloud *(or reject ;))*.

> Currently there is no automated way of adding *Anemone Connectors* to the *Anemone Cloud*.