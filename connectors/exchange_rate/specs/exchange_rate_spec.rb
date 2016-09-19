require_relative '../../../app/models/connectors/base'
require_relative '../../../app/models/connectors/exchange_rate'

describe Connectors::ExchangeRate do
  API_KEY = 'c41b4bb5-639f-4c22-9c02-202b3c2602e8'
  describe 'call' do
    it 'yields exchange rate for value' do
      czk = 250
      VCR.use_cassette('connectors/exchange_rate') do
        exchanged = Connectors::ExchangeRate.call(czk, API_KEY, 'variables' => %w(varCostEur varCostUsd))
        expect(exchanged).to eq({ 'varCostEur' => 9.24898261191269, 'varCostUsd' => 10.398901875961899 })
      end
    end

    it 'invalid args' do
      VCR.use_cassette('connectors/invalid_api_key') do
        expect(Connectors::ExchangeRate.call(250, 'invalid', 'variables' => %w(varCostEur varCostUsd)))
            .to eq(
                    { 'varCostEur' => nil, 'varCostUsd' => nil }
                )
      end
    end
  end
end