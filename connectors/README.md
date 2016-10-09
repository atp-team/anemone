# Anemone Cloud Connectors List

Here is a continuously updated list of all available *Anemone Connectors*.

## [Exchange Rate Anemone Connector](https://github.com/ceskasporitelna/anemone/tree/master/connectors/exchange_rate)

Exchange Rate Anemone Connector is a connector which performs currency conversion from `CZK` to `EUR` and `USD`.

It is using the [CSAS WebAPI](https://developers.csas.cz/) conversion service.

### Summary

| Name | Web Service | Input | Output |
|:---- |:--------:|:--------------------:|:---------------------:|
| exchangeRate | [CSAS WebAPI](https://developers.csas.cz/) | czk: *float* | eur: *float*, usd: *float* |

### Authentication

[CSAS WebAPI](https://developers.csas.cz/) API key is required for authentication.

### Usage

```json
"connectors": {
  "exchangeRate": {
    "connector": "exchangeRate",
    "variable": "varCostCzk",
    "args": {
      "apiKey": "INSERT YOUR API KEY HERE"
    },
    "output": {
      "variables": [
        "varCostEur",
        "varCostUsd"
      ]
    }
  }
}
```

## Your Connector?

Do you want to have your connector here too? It is easy!

Just take a look at our [How to make Anemone Connector](https://github.com/ceskasporitelna/anemone/blob/master/documentation/HowToMakeAnemoneConnector.md) tutorial, create your own connector and submit a pull request to this repository.