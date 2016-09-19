require 'httparty'

module Connectors
  class ExchangeRate < Base
    class << self
      def setup
      end

      # Takes 2 arguments: +czk_cost+, and +API_KEY+
      def call(*args)
        self.setup
        czk = args.fetch(0, 0)
        web_api_key = args[1]
        variables = args.fetch(2).fetch('variables').reduce(Hash.new) { |hsh, var| hsh[var] = nil; hsh }
        response = HTTParty.get('https://api.csas.cz/sandbox/webapi/api/v1/exchangerates',
                                headers: { 'WEB-API-key' => web_api_key }
        )
        return variables if response.code != 200
        response = JSON.parse(response.body)
        eur = response.find { |currency| currency['shortName'] == 'EUR' }
        usd = response.find { |currency| currency['shortName'] == 'USD' }
        variables.each_key do |var|
          variables[var] = czk/eur['valMid'] if var.match(/.*Eur/)
          variables[var] = czk/usd['valMid'] if var.match(/.*Usd/)
        end
        variables
      end
    end
  end
end