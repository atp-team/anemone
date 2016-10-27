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

> You can find more information about creation of *interface.json* files for Anemone Apps in our [How to define Anemone App User Interface in interface.json](https://github.com/ceskasporitelna/anemone/blob/master/documentation/HowToMakeAnemoneApp.md#how-to-define-anemone-app-user-interface-in-interfacejson) tutorial.

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

> You can find more information about creation of *manifest.json* files for Anemone Apps in our [How to define Anemone App Logic in manifest.json](https://github.com/ceskasporitelna/anemone/blob/master/documentation/HowToMakeAnemoneApp.md#how-to-define-anemone-app-logic-in-manifestjson) tutorial.

#### Tentacle User Interface and Logic (arduino .ino sketch) 

The last component of Anemone App is the one which will run on a Tentacle.

This component is in fact an normal **arduino .ino sketch** file which runs on the *Arduino YÚN* which is "the brain" of a Tentacle.

In order to make the development of Anemone sketches easier, we have prepared the [anemone arduino library](https://github.com/ceskasporitelna/anemone/tree/master/toolkit/anemone-arduino-library) and default [Tentacle user interface components and screens](https://github.com/ceskasporitelna/anemone/blob/master/documentation/HowToMakeAnemoneApp.md#anemone-tentacle-screens).

> You can find more information about creation of *arduino sketch* files for Anemone Apps in our [How to create Anemone App Sketch in Arduino IDE](https://github.com/ceskasporitelna/anemone/blob/master/documentation/HowToMakeAnemoneApp.md#how-to-create-anemone-app-sketch-in-arduino-ide) tutorial.

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

Below you can find some examples and conventions of Anemone Apps **Tentacle screens design**.

> When designing screens for the Tentacle part *(= sketch)* of your Anemone App **be simple**. You need to be aware the fact that Arduino YÚN has terrible refresh rate of its TFT Display, especially in case of drawing images from SD card.
> 
> In general there are two ways how you can handle Anemone App visuals on a Tentacle.
> 
> 1. You can use .bmp image files stored on SD card. But drawing big bitmaps on the TFT will take some time to the Arduino. **The drawing of a image is visible!** And since you need images on SD card, you will basically sacrifice the OTA update feature. You users will sudenly need to copy some image to the SD card of their Tentacle before they will be able to use your app.
> 2. Which brings us to the second approach how you can handle the issue. You can limit yourself just to basic graphics *(ideally just consisting from bunch of colored rectangles)* and draw these directly in code of your sketches.
> 
> **We strongly recommend you to use the option 2.** That is what we have done in the [Juicy Day example Anemone App](https://github.com/ceskasporitelna/anemone/tree/master/apps/juicy-day). And as you can see, it looks nice.

##### Anemone Tentacle Screens

The following screens will be accesible by your Anemone App by using the [Anemone Arduino Library](https://github.com/ceskasporitelna/anemone/tree/master/toolkit/anemone-arduino-library).

*Ready for App*

<img alt="Anemone Tentacle UI - Ready for app installation" src="https://github.com/ceskasporitelna/anemone/raw/master/documentation/images/app_ready_for_installation.png"> 

This screen indicates that Tentacle is **ready to load some Anemone App by OTA update** in the next *Cloud Synchronization* cycle (which happens every 1 minute).

--

*Generating Guest Code*

<img alt="Anemone Tentacle UI - Generating guest code" src="https://github.com/ceskasporitelna/anemone/raw/master/documentation/images/app_generating_code.png"> 

This screen is shown when user presses the **Cloud Button** and Tentacle *is generating a guest code*. 

> This screen will be automatically replaced by the next one when the guest code *is generated* and sent to the *Anemone Cloud*. The guest code generation *can be cancelled* by pressing the **Back Button** in the top of the Tentacle.

--

*Share Mode*

<img alt="Anemone Tentacle UI - Share mode" src="https://github.com/ceskasporitelna/anemone/raw/master/documentation/images/app_generated_code.png"> 

This screen is shown when user presses the **Cloud Button** and Tentacle *successfully generated a guest code*. When this screen is shown, the Tentacle is in the **Share Mode**.

While Tentacle is the **Share Mode**, every user *who is not owner or guest to this Tentacle already* can enter the guest code shown to his Anemone Mobile Client and became a guest to this Tentacle.

> The share mode is valid only for the first user.

The Share Mode can be cancelled by pressing the by pressing the **Back Button** in the top of the Tentacle.

> This screen will be automatically replaced by the next one when the guest code *will expire*. That will happen when the on-screen timer will reach zero.

--

*Guest Code Expired*

<img alt="Anemone Tentacle UI - Guest code expired" src="https://github.com/ceskasporitelna/anemone/raw/master/documentation/images/app_code_expired.png"> 

This screen is shown when Share Mode is cancelled or when the generated Guest Code expires.

> This screen will be automatically replaced by a Dashboard of the installed Anemone App in few seconds.

--

##### Your Anemone App Screens

The following screens are examples how screens *in your Anemone App* can look like.

*Dashboard*

<img alt="Anemone Tentacle UI - Juicy Day Currency Converter" src="https://github.com/ceskasporitelna/anemone/raw/master/documentation/images/app_converter.png"> 

Dashboard of your application can look like this *(but it does not have to)*. 

The Dashboard screen on the image above was taken from the [Juicy Day example Anemone App](https://github.com/ceskasporitelna/anemone/tree/master/apps/juicy-day).

> You can notice thow the top *solid black header* improves user the orientation on the screen and gives *a clean difference* between the input and output data areas in this case.

--

*Cloud Synchronization*

<img alt="Anemone Tentacle UI - Cloud Synchronization in progress" src="https://github.com/ceskasporitelna/anemone/raw/master/documentation/images/app_ota.png"> 

When the Tentacle will be performing the **Cloud Synchronization** *(cheking if it should perform the OTA update and syncing values of all variables)* it will **be unresponsive for few moments** *(because the microcontroller it contains does not support any sophisticated form of multi-tasking)*. The Tentacle will inform the user about this state by showing two blue and yellow lines in the top and bottom of the screen. When the **Cloud Synchronization** will complete, the lines will dissapear.

> The screen on the image above was taken from the [Juicy Day example Anemone App](https://github.com/ceskasporitelna/anemone/tree/master/apps/juicy-day).

--

*Menu*

<img alt="Anemone Tentacle UI - Menu" src="https://github.com/ceskasporitelna/anemone/raw/master/documentation/images/app_menu.png">

Every Anemone App can *(and should)* have **a menu**. Menu can contain two or more *menu items*. Every *menu item* should have a *name* and *icon* for the selected and for the deselected state.

The menu is shown when the *Menu Knob* on the right side of Tentacle **is pressed**. Menu items can be selected by **rotating** the **Menu Knob** up or down. By presing the *Menu Knob* the selected menu item **is invoked**. Menu screen can be **dismissed** by pressing the *Back Button* on the top of the Tentacle.

> The screen on the image above was taken from the [Juicy Day example Anemone App](https://github.com/ceskasporitelna/anemone/tree/master/apps/juicy-day).

### How to register Anemone App in the *Anemone Cloud Administration*

> When uploading `.hex` file of your Anemone App sketch, **please always upload the version WITHOUT the bootloader!** Tentacle will append the bootloader automatically while performing the OTA update.
> 
> Uploading a `.hex` file with bootloader **will not work**. You will be able to *upload it to Anemone Cloud*, but the subsequent OTA update of the Tentacle **will fail**.

### How to test the app on your Tentacle

We strongly recommend you to test your Anemone App sketch on the Tentacle directly **by uploading it by serial connection** from the *Arduino IDE*.

When something will be bad and you will **have a bug in your sketch**, the Tentacle **might not be able to perform the OTA** any longer.

In that case uploading a fixed sketch by serial interface in *a classic Arduino way* usually helps.

When your sketch will work as you wanted on your Tentacle, then it is time to upload its `.hex` file to the Anemone Cloud and try to perform a *OTA update* to it.

### How to Submit the app for Review in the Anemone Cloud Administration

When your Anemone App is tested and ready, you can **submit it for review**.

You can do this by logging into your *Anemone Cloud Administration*, and pressing the "**Submit for Review**" link next to your Anemone App.

*[#anemoneCloud](https://twitter.com/hashtag/anemoneCloud)*