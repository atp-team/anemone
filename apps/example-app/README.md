# Example App Anemone App

*Author: [Juicymo s.r.o.](http://www.juicymo.cz)*

Example App is a minimal example of working Anemone app build by the Anemone Team.

Example App is doing only one thing and that is showing a text "Example App" on the display.

As every Anemone App, even the Example App Anemone App contains a functionality which is required (received from the [Anemone Arduino Library](https://github.com/ceskasporitelna/anemone/tree/master/toolkit/anemone-arduino-library), which is the following:

* By pressing a *cloud button* (the one in front) user can switch Tentacle to the *share mode* in which Tentacle will generate (and show) a 4-digit guest code, which can be used by another user to access this tentacle as a *guest*.
* Share mode can be cancelled any time by pressing a back button.
* Every 60s the Tentacle is performing a synchronization with Anemone Cloud. In this moment it will sync values of all variables and check if there is a need to perform OTA update of installed Anemone App.

You can install Example App Anemone App on your Tentacle from the Mobile Client or from the Anemone Cloud Administration.

## Variables

Example App is not using any variable.

## Connectors

Example App is not using any connector.