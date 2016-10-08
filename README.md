<img class="icon" alt="Anemone Platform" src="https://github.com/ceskasporitelna/anemone/raw/master/documentation/images/anemone_logo.png" width="100">

> "Look at you hacker, in order to use me, you must understand first." -- Anemone

## Introducing the Platform

Anemone is an open platform which allows you to experiment with *Internet of Things*. Anemone allows you to easily **build open hardware device** and to **create a simple apps** which will run *both in cloud and on mobile devices*.

First take a look at our website [http://www.anemone.cloud](http://www.anemone.cloud).

Then continue reading.

## Platform ecosystem

Anemone ecosystem consists of:

* **Anemone Overview** (you are reading it now)
* **Anemone Platform** which consists of:
  * [Anemome Cloud](http://www.anemone.cloud) 
  * **Anemone Mobile Client** iOS & Android apps (you can download them from [www.anemone.cloud](http://www.anemone.cloud))
  * [Anemone Tentacle](https://github.com/ceskasporitelna/anemone/blob/master/documentation/HowToBuildAnemoneTentacle.md) open hardware device you can build and 3D print
* [Anemone Documentation](https://github.com/ceskasporitelna/anemone/tree/master/documentation) where you can read everything you need to know
* [Anemome Toolkit](https://github.com/ceskasporitelna/anemone/tree/master/toolkit) which you need in order to create a Tentacle or build Anemone App
* [Anemome Apps Repository](https://github.com/ceskasporitelna/anemone/tree/master/apps)
* [Anemome Cloud Connectors List](https://github.com/ceskasporitelna/anemone/tree/master/connectors)

More information about the Anemone Platform are provided below.

## Platform architecture

Anemone has three main parts:

* Mobile Client
* Cloud
* Tentacle

**Mobile Client** is iOS and Android application which allows you to manage *Tentacles* and control *Anemone Apps*. You can download it for free from Apple AppStore and Google Play Store. Both links are on our website [http://www.anemone.cloud](http://www.anemone.cloud).

<img alt="Anemone Mobile Client - List of Tentacles" src="https://github.com/ceskasporitelna/anemone/raw/master/documentation/images/mobile_client_1_tentacles_list.png" width="300"> <img alt="Anemone Mobile Client - Tentacle Detail" src="https://github.com/ceskasporitelna/anemone/raw/master/documentation/images/mobile_client_2_tentacle_detail.png" width="300">

**Cloud** is the final component of the platform which connects the Tentacles to the Mobile Client. But that is not all. The Anemone Cloud can connect both the Mobile Client and Tentacles to other API service in the internet using **Connectors**.

<img alt="Anemone Platform Architecture" src="https://github.com/ceskasporitelna/anemone/raw/master/documentation/images/anemone_architecture.png" width="600">

**Tentacle** is open hardware device based on Arduino YÚN which is the *Internet of Things* part the our platform. You can either *connect as a guest* to a Tentacle of your friend, or you can *build your own* (which will recognize you as its master).

<img alt="Anemone Tentacle - View from Right" src="https://github.com/ceskasporitelna/anemone/raw/master/documentation/images/tentacle_render_a.png" width="300"> <img alt="Anemone Tentacle - View from Left" src="https://github.com/ceskasporitelna/anemone/raw/master/documentation/images/tentacle_render_b.png" width="300">

The *Cloud*, *Mobile Client* and *Tentacle* together form a platform where **Anemone Apps** can run.

And *Anemone Apps* are here for you *to use them*, *to develop them* and mainly **to have some fun with them**.

## What can be achieved with the platform?

With Anemone Platform you can do the following:

* You can display textual information from the the Anemone Cloud on Tentacle display *(information is stored inside variables in the cloud component of Anemone app)*
* Tentacle can change value of variable of it's app cloud component (eg. when some button on the Tentacle is pressed or when some data is measured)
* You can create so called "Anemone Apps" which contains variable which can be shown on Tentacle display and/or in the Mobile Client app. For you can let user enter some data using his mobile phone, adjust this data in the cloud and show result on the Tentacle. Or you can let user interact with the Tentacle and process this interaction in the cloud and show the result in the mobile app.
* The platform is done in a way that owner of a Tentacle can share it to his friend or change the running Anemone App using the OTA *(Over-The-Air)* update.

> The **Anemone Platform is completely OPEN**. Everybody can [became a user by signing up for free](TODO). Every user can either receive a guest access or can [build his own](TODO) Tentacle. To a Tentacle he can then install some apps from our [public repository of Anemone Apps](https://github.com/ceskasporitelna/anemone/tree/master/apps) or he can [create his own app](TODO).

## How it works? 

> Main goal of Anemone Platform is to provide a place where *Anemone Apps* can live.

Anemone App is a tiny piece of software which can be **build by you**. We have designed the Anemone platform in a way that it will be extremely easy for you to make new Anemone Apps.

### What is Anemone App?

Anemone app is every application which runs on the Anemone platform.

Every Anemone app has three components:

* Mobile User Interface
* Cloud Logic
* Tentacle User Interface and Logic

Every of these three components of an Anemone App runs in one part of Anemone platform:

* **Mobile User Interface** runs in the *Mobile Client* app
* **Cloud Logic** runs in the *Cloud*
* **Tentacle User Interface and Logic** runs on the *Tentacle*

When your create these three components you have successfully create an Anemone App. Every Anemone App is explicitly defined use by these three components.

What the components are in fact?

* Mobile User Interface is defined by an **interface.json** file
* Cloud Logic is defined by an **manifest.json** file
* Tentacle User Interface and Logic is defined by **arduino .ino sketch** which uses our *Anemone arduino library*

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

<img alt="Anemone App Communication Schema" src="https://github.com/ceskasporitelna/anemone/raw/master/documentation/images/cloud_communication.jpg" width="600">

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

<img alt="Anemone Tentacle UI - Ready for app installation" src="https://github.com/ceskasporitelna/anemone/raw/master/documentation/images/app_ready_for_installation.png"> <img alt="Anemone Tentacle UI - Currency Converter" src="https://github.com/ceskasporitelna/anemone/raw/master/documentation/images/app_converter.png"> <img alt="Anemone Tentacle UI - OTA Update in progress" src="https://github.com/ceskasporitelna/anemone/raw/master/documentation/images/app_ota.png"> <img alt="Anemone Tentacle UI - Generating guest code" src="https://github.com/ceskasporitelna/anemone/raw/master/documentation/images/app_generating_code.png"> <img alt="Anemone Tentacle UI - Share mode" src="https://github.com/ceskasporitelna/anemone/raw/master/documentation/images/app_generated_code.png"> <img alt="Anemone Tentacle UI - Guest code expired" src="https://github.com/ceskasporitelna/anemone/raw/master/documentation/images/app_code_expired.png"> <img alt="Anemone Tentacle UI - Menu" src="https://github.com/ceskasporitelna/anemone/raw/master/documentation/images/app_menu.png">

> You can find more information about creation of *arduino sketch* files for Anemone Apps in our [How to create Anemone App Sketch in Arduino IDE](TODO) tutorial.

## This looks Awesome! How can I start?

You can use the Anemone platform either as a **User** or as a **Developer**.

In order to start *as a User*, all you need to do is:

1. [Sign up](http://www.anemone.cloud/users/sign_up) for free on the Anemone platform website. Select your account avatar while doing so (by a name of the icon only - that is the real fun!)
2. Download the **Mobile Client app for iOS or Android** (you can find links to apps on our website [http://www.anemone.cloud](http://www.anemone.cloud))
3. Find some **Tentacle** which you would like to control. In order to control a Tentacle, you need to either *own it* (which means to [build it](https://github.com/ceskasporitelna/anemone/blob/master/documentation/HowToBuildAnemoneTentacle.md) first), or be invited to it *as a guest*
4. Take a full control of the Tentacle. You can **control the running app** as both guest and owner. Or **switch the running app** for another one or **trigger Tentacle share mode** as owner.  Both can be done from the Mobile Client or Cloud administration

When starting *as a Developer* do the following:

1. [Sign up](http://www.anemone.cloud/users/sign_up) for free on the Anemone platform website. Select your account avatar while doing so *(by a name of the icon only - that is only way which contains the real fun!)*
2. Download the **Mobile Client app for iOS or Android** (you can find links to apps on our website [http://www.anemone.cloud](http://www.anemone.cloud))
3. [Build](https://github.com/ceskasporitelna/anemone/blob/master/documentation/HowToBuildAnemoneTentacle.md) a **Tentacle**. Every real developer has its own Tentacle 
4. [Make an Anemone app](https://github.com/ceskasporitelna/anemone/blob/master/documentation/HowToMakeAnemoneApp.md). Prepare the *interface.json*, *manifest.json* and *arduino sketch* .hex files for your application. Login to the cloud administration **and add your first Anemone app**
5. **Install the app on your Tentacle** via *OTA* from cloud administration (by pressing a Install button)
5. **Test the app** on your Tentacle when being in a *sandbox* mode.
6. **Submit the app for approval** to the public apps repository via button in the cloud administration
7. The anemone team will review and **approve the app**
8. Every user of the platform can **download the app and use it**
9. Congratulations - you are now Anemone apps developer. **The world is yours**!

## I want more of it! - What to do next?

1. Check out our [website](http://www.anemone.cloud)
2. [Sign up](http://www.anemone.cloud/users/sign_up) for free and [download the Mobile Client](http://www.anemone.cloud)
3. Read the [How to build Anemone Tentacle](https://github.com/ceskasporitelna/anemone/blob/master/documentation/HowToBuildAnemoneTentacle.md) tutorial
4. Read the [How to make Anemone App](https://github.com/ceskasporitelna/anemone/blob/master/documentation/HowToMakeAnemoneApp.md) tutorial, or directly
	1. [How to define Anemone App Logic in manifest.json](TODO)
	2. [How to define Anemone App User Interface in interface.json](TODO)
	3. [How to create Anemone App Sketch in Arduino IDE](TODO)
5. Read the [How to make Anemone Connector](https://github.com/ceskasporitelna/anemone/blob/master/documentation/HowToMakeAnemoneConnector.md) tutorial
6. You may be also interested in the [Anemone Apps Repository](https://github.com/ceskasporitelna/anemone/tree/master/apps), [List of available Anemone Connectors](https://github.com/ceskasporitelna/anemone/tree/master/connectors) and [Anemone Arduino Library documentation](https://github.com/ceskasporitelna/anemone/tree/master/toolkit/anemone-arduino-library)
7. Explore the "Juicy Day" [example Anemone App on our GitHub](https://github.com/ceskasporitelna/anemone/tree/master/apps/juicy-day)
8. Write us. Tweet about us, write on Facebook, make a blogpost. Use hashtag **#anemoneCloud**.

## Who Is Behind This?

Anemone platform is a result of cooperation between [Honza Sechovec](https://twitter.com/jansechovec) and [Juicymo](http://www.juicymo.cz).

It could never be created without support of guys from [Česká Spořitelna](https://developers.csas.cz)

Anemone has been created with love in Prague.

In case of any question or issue, feel free to add a GitHub Issue in this repository.

<a href="http://www.juicymo.cz"><img alt="Juicymo - Mobile Apps Development" src="https://github.com/ceskasporitelna/anemone/raw/master/documentation/images/juicymo.png" width="100"></a>

### Special thanks

For their great effort we owe a BIG thank to the following people and entities from the joint project development team (everybody did *a lot more* then what was expected from him):

* *Pedro Pinto da Silva* for the outstanding graphical design of the entire platform including website, mobile app, Arduino app UI and infographics. This platform design has a story.
* *Martin Svoboda* for the development of Anemone Cloud Ruby on Rails application, manifest and interface JSON parsers and database.
* *Šimon Kautský* for the development of Anemone Mobile Client app both for iOS and Android in Unity3D and for solving all these ugly platform specific bugs.
* *Filip Bursík* for the development of Arduino part of Anemone platform in C and for all those dreamless nights when the program did not fit the small Arduino YÚN memory.
* *Michal Mlejnek* for the huge amount of Anemone Tentacle 3D case model iterations in Blender - including the final one which you can print and enjoy.
* *Jana Moudrá* for coding the Anemone platform presentational website (the one at [http://www.anemone.cloud](http://www.anemone.cloud)). Fully responsive with all the cute JS features.
* *Honza Sechovec* for the vision, guidance and mainly for the patience. The development of the platform took a bit longer than expected, but the result is worth it.
* *Tomáš Jukin* for the platform architecture and the fact that all the stuff fits well together. And for the ugly electronical stuff, the documentation, slicing, soldering and 3D printing.
* *Kanárek* (which is a [Prusa3D i3 MK2 3D printer](http://www.prusa3d.cz/#i3-printer)) for printing every single iteration of the Anemone Tentacle 3D case model and still work.

### Used technologies

> "They say great science is built on the shoulders of giants." -- Cave Johnson

Anemone Platform is build using well known technologies you should not miss. 

* Anemone Tentacle is an Open Hardware device build around on the Arduino YÚN and Arduino TFT Display.
* Anemone Cloud is created using Ruby on Rails
* Anemone Mobile Client is programmed in Unity

<img alt="Arduino YÚN" src="https://github.com/ceskasporitelna/anemone/raw/master/documentation/images/fritzing-arduino-yun.png" width="100"> <img alt="Arduino TFT Display" src="https://github.com/ceskasporitelna/anemone/raw/master/documentation/images/fritzing-arduino-tft.png" width="100"> <img alt="Open Hardware" src="https://github.com/ceskasporitelna/anemone/raw/master/documentation/images/open_hardware.png" width="60"> <img alt="Ruby" src="https://github.com/ceskasporitelna/anemone/raw/master/documentation/images/ruby.png" width="60"> <img alt="Rails" src="https://github.com/ceskasporitelna/anemone/raw/master/documentation/images/rails.png" width="60"> <img alt="Unity" src="https://github.com/ceskasporitelna/anemone/raw/master/documentation/images/unity.png" width="60">

## How can I contribute?

1. Join the platform! Either as a User or Developer, you can join the Anemone platform and explore the world of IoT in a fun way. See [http://www.anemone.cloud](http://www.anemone.cloud).
2. Spread the word! I you know somebody who might be interested in our platform invite him ale show him your Tentacle.
3. Make your own apps based on [manual](https://github.com/ceskasporitelna/anemone/blob/master/documentation/HowToMakeAnemoneApp.md).
4. Make new connectors and submit them as pull requests to this repository.
5. Interested in serious development? Wanna extend the platform itself? Contact Honza at honza@flexer.cz.

## FAQ

### I pluged my Tentacle, but it has blank screen and it "is not doing anything". How to solve this?

> Arduino YÚN is a terribly slow device. So when you turn it on (typicaly by plugining in the USB cable), it will just turn on the green LED an do nothing. In this time the Arduino YÚN Linux/WiFi part is booting up. When this will finish, the ÝUN will turn on a white LED. And this is the moment when it will start the Arduino sketch ans hence your Anemone App as well.
> 
> After the initial setup a so called "Initial Arduino Sketch" is installed on your Tentacle by the tentacle.sh script you have downloaded from the Anemone Cloud Admin. This sketch just shows the "Ready for app install" text and image.
> 
> <img alt="Anemone Tentacle UI - Ready for app installation" src="https://github.com/ceskasporitelna/anemone/raw/master/documentation/images/app_ready_for_installation.png">
> 
> After 60 seconds, the "Initial Arduino Sketch" will try to perform an OTA update.
> 
> Because the hardware limitations of the Arduino YÚN *(especially the way how the SPI bus is wired to the ICSP pins on YÚN)*, the TFT screen needs to be turned off prior an OTA update. This is why the screen goes black when OTA update is in progress.
> 
> And because Arduino YÚN is quite slow, the OTA update can take up to 5 minutes event on fast internet connection.
> 
> So the solution of this is **just wait till the OTA update will complete**. Your app will run after it.*

**We know that this is not the best user-friendly behavior and we are working on a possible solution which could make this better in future. So have crossed for us fingers...*

### How can I connect to a Tentacle as a Guest?

> You need to access the Tentacle physically and press the *cloud button* (located below the left bottom corner of the screen). Or you can convince the Tentacle owner to press the *key button* in his Mobile Client app on his Tentacle info page.

> This will initiate a **share mode** of the Tentacle. When in this mode, Tentacle will show a four digit guest code on its screen - eg. 1234.

> When you physically access a Tentacle in share mode, you can type its guest code to your Mobile Client app (after pressing the *Add Tentacle* button on the dashboard).

> The Tentacle will now appear in your Mobile Client under the *Guest Boxes* label. You can now control the *Anemone App* which is running on it.

### How can I build a Tentacle?

> Just follow our [manual](https://github.com/ceskasporitelna/anemone/blob/master/documentation/HowToBuildAnemoneTentacle.md). It includes a *part list* and even a *model of cute case* which can be 3D printed! All the difficult stuff is done, what remains are just the fun parts ;).

## Terms and License

This software is licensed under [MIT license](https://github.com/ceskasporitelna/anemone/blob/master/LICENSE.md).

<img alt="Anemone Tentacle" src="https://github.com/ceskasporitelna/anemone/raw/master/documentation/images/tentacle_gloss.png" width="300">




