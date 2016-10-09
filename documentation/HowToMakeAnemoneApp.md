# How to make Anemone App

Anemone App is any application running in the [Anemone Platform](http://www.anemone.cloud).

In this tutorial we will explain how Anemone Apps work and how you can make your own.

> We maintain a [list of all Anemone Apps](https://github.com/ceskasporitelna/anemone/tree/master/apps), feel free to take a look around and get some inspiration.

## How Anemone App works

Every Anemone App consist of three parts:

1. Manifest
2. Interface
3. Sketch

Every Anemone App runs on three places (which is why it has three parts). Every part runs on given place and has a give purpose.

1. **Manifest** (aka *Cloud Logic*) defines how the app **Worker** will behave inside the *Anemone Cloud*
2. **Interface** (aka *Mobile User Interface*) defines how the app **User Interface** inside the *Anemone Mobile Client* will look like
3. **Sketch** (aka *Tentacle User Interface and Logic*) defines how the **Arduino part of the app** will behave and look like inside the *Anemone Tentacle*

> If you do not know what *Anemone Cloud*, *Anemone Mobile Client* or *Anemone Tentacle* are, take a look at the [Anemone Platform Overview](https://github.com/ceskasporitelna/anemone).

### How all the parts play together?

The part of *Anemone App* which lives *(and run)* inside the Tentacle *(= sketch)* and the part which lives *(and run)* inside the Mobile Client never talk directly to each other. 

Instead they both talk only to the part of *Anemone App* which lives *(and run)* inside the Anemone Cloud. That part is called a **Worker**.

<img alt="Anemone App Communication Schema" src="https://github.com/ceskasporitelna/anemone/raw/master/documentation/images/cloud_communication.jpg" width="600">

### Variables

Every Anemone App can have a stored state. This state is represented by a set of variables. In theory Anemone App is not required to have any variable, but in that case it is not much useful.

Variables are always stored inside the **Worker** in the *Anemone Cloud*.

From there the Variables can be accessed either from Tentacle (by the app sketch) or from the Mobile Client (by the app interface).

Variables can be accessed from both places in **read** or **write** mode *(if that is allowed by the app manifest file)*.

### Components

Every Anemone App is **explicitly defined by the three components**.

* *Mobile User Interface* is defined by an **interface.json** file
* *Cloud Logic* is defined by an **manifest.json** file
* *Tentacle User Interface and Logic* is defined by **arduino .ino sketch** which uses our [Anemone Arduino Library](https://github.com/ceskasporitelna/anemone/tree/master/toolkit/anemone-arduino-library)

Now lets take a bit *deeper* look on the individual components.

#### Mobile User Interface (interface.json)

The *interface.json* file describes list of **input** or **output** components which together form the user interface of Anemone App which is shown inside the Mobile Client when your Anemone App is open.

Thought this interface you can either read data from your Anemone App or provide data input. All data are in fact loaded and stored to the Anemone Cloud (from where the Tentacle will load them).

When defining the Anemone App Mobile User Interface you can use set of prepared components.

Interface of your Anemone App can look like this:

<img alt="Anemone App Interface Example" src="https://github.com/ceskasporitelna/anemone/raw/master/documentation/images/mobile_client_3_app_dashboard.png" width="300">

In order to make this Mobile User Interface, you need to create an **interface.json** file which can look like this:

```json
{
  "platform": {
    "appId": "juicy-day",
    "driver": "anemone",
    "type": "interface",
    "version": 1
  },
  "input": {
    "inCostCzk": {
      "type": "numberField",
      "label": "Cost in CZK"
    }
  },
  "output": {
    "outCostEur": {
      "type": "numberLabel",
      "label": "Cost in EUR"
    }
  }
}
```

> You can find more information about creation of *interface.json* files for Anemone Apps in our [How to define Anemone App User Interface in interface.json](TODO) tutorial.

#### Cloud Logic (manifest.json)

The *manifest.json* file describes list of **variables** and **bindings** which together form the cloud component of every *Anemone App*.

##### Variables

Every *variable* has a **name** and **data type**. And in addition an information whenever it is **readable** (get) or **writeable** (set) from the *Tentacle* (the readability and writeablity from the Mobile Client is defined on other place of the *manifest.json* - in *bindings*).

```json
{
  "variables": {
    "varCostCzk": {
      "dataType": "float",
      "get": true,
      "set": false
    },
    "varCostEur": {
      "dataType": "float",
      "get": true,
      "set": false
    }
  }
}
```

##### Bindings

The second part of the *manifest.json* file contains the list of bindings. There are two types of bindings - user **interface** bindings and cloud **connectors** bindings.

```json
{
  "bindings": {
    "interface": {
    },
    "connectors": {
    }
  }
}
```

User interface bindings (defined inside the "interface" section) describe **bindings of variables to user interface components of Mobile User Interface** defined in *interface.json*.

```json
{
  "bindings": {
    "interface": {
      "bindCostInCzk": {
        "variable": "varCostCzk",
        "from": "inCostCzk"
      },
      "bindCostInEur": {
        "variable": "varCostEur",
        "to": "outCostEur"
      }
    },
  }
}
```

The connectors bindings (defined inside the "connectors" section) describe **bindings of variables to Anemone Cloud Connectors**.

Connector is a component of Anemone Cloud which provides access to other web services (like Twitter of CSAS WebAPI).

Connectors are integrate in the Anemone Cloud. List of all existing connectors can be found [here](https://github.com/ceskasporitelna/anemone/tree/master/connectors). You can [create new connectors based on our manual](https://github.com/ceskasporitelna/anemone/blob/master/documentation/HowToMakeAnemoneConnector.md).

The connector definition look like this:

```json
{
  "bindings": {
    "connectors": {
      "exchangeRate": {
        "connector": "exchangeRate",
        "variable": "varCostCzk",
        "args": {
          "apiKey": "INSERT YOUR API KEY HERE"
        },
        "output": {
          "variables": [
            "varCostEur"
          ]
        }
      }
    }
  }
}
```

The complete *manifest.json* file can look like this:

```json
{
  "platform": {
    "appId": "juicy-day",
    "driver": "anemone",
    "type": "manifest",
    "version": 1
  },
  "variables": {
    "varCostCzk": {
      "dataType": "float",
      "get": true,
      "set": false
    },
    "varCostEur": {
      "dataType": "float",
      "get": true,
      "set": false
    }
  },
  "bindings": {
    "interface": {
      "bindCostInCzk": {
        "variable": "varCostCzk",
        "from": "inCostCzk"
      },
      "bindCostInEur": {
        "variable": "varCostEur",
        "to": "outCostEur"
      }
    },
    "connectors": {
      "exchangeRate": {
        "connector": "exchangeRate",
        "variable": "varCostCzk",
        "args": {
          "apiKey": "INSERT YOUR API KEY HERE"
        },
        "output": {
          "variables": [
            "varCostEur"
          ]
        }
      }
    }
  }
}
```

> You can find more information about creation of *manifest.json* files for Anemone Apps in our [How to define Anemone App Logic in manifest.json](TODO) tutorial.

#### Tentacle User Interface and Logic (arduino .ino sketch) 

The last component of Anemone App is the one which will run on a Tentacle.

This component is in fact an normal **arduino .ino sketch** file which runs on the *Arduino YÚN* which is "the brain" of a Tentacle.

In order to make the development of Anemone sketches easier, we have prepared the [anemone arduino library](https://github.com/ceskasporitelna/anemone/tree/master/toolkit/anemone-arduino-library) and default [Tentacle user interface components and screens](TODO).

> You can find more information about creation of *arduino sketch* files for Anemone Apps in our [How to create Anemone App Sketch in Arduino IDE](TODO) tutorial.

## How to create new Anemone App

In order to create an **Anemone App** you need to do the following:

1. Define Anemone App Logic in *manifest.json*
2. Define Anemone App User Interface in *interface.json*
3. Create Anemone App Sketch in Arduino IDE
4. Register Anemone App in the Anemone Cloud Administration
5. Test the app on your Tentacle
6. Submit the app for Review in the Anemone Cloud Administration
7. If you want to release your Anemone App as **Open Source** *(which is a great way how to help others)*, push your app source files as a pull request to the [Anemone Apps Repository](https://github.com/ceskasporitelna/anemone/tree/master/apps), we will review it an accept.

Now lets take a closer look on the individual steps.

### How to define Anemone App Logic in *manifest.json*

> You can use **Connectors** as a part of your *Anemone App Logic*. You can find all available connectors in our [list of Anemone Connectors](https://github.com/ceskasporitelna/anemone/tree/master/connectors). Do you miss a connector for your favorite Web API? [Create it](https://github.com/ceskasporitelna/anemone/blob/master/documentation/HowToMakeAnemoneConnector.md).

### How to define Anemone App User Interface in *interface.json*

### How to create Anemone App Sketch in Arduino IDE

#### Tentacle user interface components and screens

##### Anemone Tentacle Screens

<img alt="Anemone Tentacle UI - Ready for app installation" src="https://github.com/ceskasporitelna/anemone/raw/master/documentation/images/app_ready_for_installation.png"> 

<img alt="Anemone Tentacle UI - Generating guest code" src="https://github.com/ceskasporitelna/anemone/raw/master/documentation/images/app_generating_code.png"> 

<img alt="Anemone Tentacle UI - Share mode" src="https://github.com/ceskasporitelna/anemone/raw/master/documentation/images/app_generated_code.png"> 

<img alt="Anemone Tentacle UI - Guest code expired" src="https://github.com/ceskasporitelna/anemone/raw/master/documentation/images/app_code_expired.png"> 

##### Your Anemone App Screens

<img alt="Anemone Tentacle UI - Juicy Day Currency Converter" src="https://github.com/ceskasporitelna/anemone/raw/master/documentation/images/app_converter.png"> 

<img alt="Anemone Tentacle UI - OTA Update in progress" src="https://github.com/ceskasporitelna/anemone/raw/master/documentation/images/app_ota.png"> 

<img alt="Anemone Tentacle UI - Menu" src="https://github.com/ceskasporitelna/anemone/raw/master/documentation/images/app_menu.png">

### How to register Anemone App in the *Anemone Cloud Administration*

### How to test the app on your Tentacle

### How to Submit the app for Review in the Anemone Cloud Administration