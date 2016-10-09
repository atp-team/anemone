# Exchange Rate Anemone Connector

Exchange Rate Anemone Connector is a connector which performs currency conversion from `CZK` to `EUR` and `USD`.

It is using the [CSAS WebAPI](https://developers.csas.cz/) conversion service.

## Summary

| Name | Web Service | Input | Output |
|:---- |:--------:|:--------------------:|:---------------------:|
| exchangeRate | [CSAS WebAPI](https://developers.csas.cz/) | czk: *float* | eur: *float*, usd: *float* |

## Authentication

[CSAS WebAPI](https://developers.csas.cz/) API key is required for authentication.

## Usage

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