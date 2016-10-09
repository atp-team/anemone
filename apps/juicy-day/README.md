# Juicy Day Anemone App

*Author: [Juicymo s.r.o.](http://www.juicymo.cz)*

Juicy Day is an example Anemone app build by the Anemone Team.

Juicy Day allows you to enter amount of money in the CZK currency through its Mobile Client interface. This amount is then sent to the cloud, where it is converted to USD and EUR via the *"exchangeRate"* Anemone Cloud Connector. The resulting amounts in USD and EUR are then shown to the user both on his mobile phone (in the Mobile Client) and on the Tentacle display.

On the side of a Tentacle the Juicy Day Anemone app shows all features of the Tentacle device. It contains an app dashboard where it shows information loaded from the cloud (which are the money amounts in CZK, USD and EUR). By pressing the side know, user can access the Tentacle menu, from where he can either turn on the in-build buzzer or start fading the in-build LEDs. By pressing the top back button he can go back to the app dashboard.

As every Anemone App, even the Juicy Day Anemone App contains a functionality which is required (received from the [Anemone Arduino Library](https://github.com/ceskasporitelna/anemone/tree/master/toolkit/anemone-arduino-library), which is the following:

* By pressing a *cloud button* (the one in front) user can switch Tentacle to the *share mode* in which Tentacle will generate (and show) a 4-digit guest code, which can be used by another user to access this tentacle as a *guest*.
* Share mode can be cancelled any time by pressing a back button.
* Every 60s the Tentacle is performing a synchronization with Anemone Cloud. In this moment it will sync values of all variables and check if there is a need to perform OTA update of installed Anemone App.

You can install Juicy Day Anemone App on your Tentacle from the Mobile Client or from the Anemone Cloud Administration.

## Screens

<img alt="Anemone Tentacle UI - Juicy Day Currency Converter" src="https://github.com/ceskasporitelna/anemone/raw/master/documentation/images/app_converter.png"> <img alt="Anemone Tentacle UI - OTA Update in progress" src="https://github.com/ceskasporitelna/anemone/raw/master/documentation/images/app_ota.png"> <img alt="Anemone Tentacle UI - Menu" src="https://github.com/ceskasporitelna/anemone/raw/master/documentation/images/app_menu.png">

## Variables

Juicy Day is using 3 variables.

| Name | Datatype | Readable by Tentacle | Writeable by Tentacle |
|:---- |:--------:|:--------------------:|:---------------------:|
| varCostCzk | float | Yes | No |
| varCostEur | float | Yes | No |
| varCostUsd | float | Yes | No |

## Connectors

Juicy Day is using 1 connector.

| Name | Web Service | Input | Output |
|:---- |:--------:|:--------------------:|:---------------------:|
| [exchangeRate](https://github.com/ceskasporitelna/anemone/tree/master/connectors/exchange_rate) | [CSAS WebAPI](https://developers.csas.cz/) | varCostCzk | varCostEur, varCostUsd |

[back to the list of apps](https://github.com/ceskasporitelna/anemone/tree/master/apps)