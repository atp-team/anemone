# How to build Anemone Tentacle

Anemone Tentacle is a DIY Open Hardware device you can build and 3D print a cute case for it.

> Tentacle is fully Open Hardware device based on Arduino YÚN and Arduino TFT Display. It can be used as part of [Anemone Platform](http://www.anemone.cloud) or completelly standalone as a nice case for Arduino YÚN and Arduino TFT display.

## How Tentacle looks like?

TODO 2 images

Tentacle has three hardware controls which you can see on the following image:

TODO image

* The **top button** is used as a *back button* by the [Anemone arduino library](https://github.com/ceskasporitelna/anemone/tree/master/toolkit/anemone-arduino-library), but can be used in your Anemone apps as well
* The **side knob** is used as a *menu button & controller* and should not be used for any other purpose than a menu trigger and navigation
* The **front button** is used as a *cloud button* by the Anemone arduino library and it should not be used in your Anemone app at all *(the user should always have the ability to switch Tentacle to the share mode - without caring about where in your Anemone app he is currently present)*

> Of course these limitations/recomendations apply only when you use the Tentacle inside the [Anemone Platform](http://www.anemone.cloud) with the [Anemone arduino library](https://github.com/ceskasporitelna/anemone/tree/master/toolkit/anemone-arduino-library). When using the Tentacle outside of the Anemone ecosystem, feel free to repurpose all the buttons as you see fit.

## That is nice! How to build it?

In this tutorial we will guide you throught the Tentacle building process.

In order to build your very own Tentacle you need to do the following:

1. Buy *(or somehow gather)* all the needed parts. See the [parts list](#parts-list).
2. Build the Tentacle core *(= put together the Tentacle electronic circuits)*
3. Build the Tentacle outer shell *(= 3D print the Tentacle case)*
4. Integrate Tentacle to into the shell *(= insert the electronic circuits into the 3D printed case)*
5. Install the Tentacle software
6. Connect your Tentacle to the [Anemone Cloud](http://www.anemone.cloud).

And that's it! ;)

## Step 1 - Gather Tentacle parts

In order to build a Tentacle you will need the following components:

* 1x [Arduino YÚN](https://www.arduino.cc/en/Main/ArduinoBoardYun)
* 1x [Arduino TFT LCD Display](https://www.arduino.cc/en/Main/GTFT)
* 1x [Rotary Encoder Keyes KY-040](http://henrysbench.capnfatz.com/henrys-bench/arduino-sensors-and-input/keyes-ky-040-arduino-rotary-encoder-user-manual/) (used as *menu knob*)
* 1x [Buzzer YL-44](https://rydepier.wordpress.com/2015/05/24/active-buzzer-alarm/)
* 1x [Microswitch TC-0108-T](https://www.gmelectronic.com/tc-0108-t) (used as *cloud button*)
* 1x [Red Switch P-PB303B](https://www.gmelectronic.com/p-pb303b-red) (used as *back button*)
* 2x [Green Super Flux LED 913PG2C](https://www.gmelectronic.com/super-flux-led-sfl-pure-green-2000-110-130) (used as *back button backlight*)
* 2x [Optocoupler BPC-817C](https://www.gmelectronic.com/bpc-817c) (or similar working with 5V input/output voltage)
* 2x [Resistor 220 Ohm](TODO)
* 2x [Resistor 10 Kiloohm](TODO)

And the following passive parts:

* 1x [Prototype Shield](TODO)
* 1x [Small Breadboard TODOx10](TODO)
* 1x [Stripboard TODOxTODO](TODO)
* 1x [Blue Wire](TODO)
* TODOx [Jumper Wire M-F 10cm](TODO)
* TODOx [Jumper Wire M-F 20cm](TODO)

TODO image with all parts

### Parts List

In order to make your life easier we have prepared a list of links where you can buy all the Tentacle parts:

> This is just a hint ;). All the parts are **Open Hardware** you can buy them in your favourite shop, local hardware store, etc. 

| # | Part | Where to buy in Czech Republic | Where to buy Worldwide |  Cost |
|:------------- |:------------- |:---------------:|:-------------:| -------------:|
| 1 | Arduino YÚN |  |  |  |
| 1 | Arduino TFT LCD Display |  |  |  |
| 1 | Rotary Encoder Keyes KY-040 | https://goo.gl/HBKuvv | https://goo.gl/aWtrAF | €0,50 |
| 1 | Buzzer YL-44 |  |  |  |
| 1 | Microswitch TC-0108-T | https://goo.gl/ncyT34 | https://goo.gl/iff8Z7 | €0,13 |
| 1 | Red Switch P-PB303B | https://goo.gl/mJq2Rl | https://goo.gl/SXAANZ | €0,45 |
| 2 | Green Super Flux LED 913PG2C | https://goo.gl/e5RzAD | https://goo.gl/xWg07e | €0,40 |
| 2 | Optocoupler BPC-817C | https://goo.gl/SSWsRn | https://goo.gl/BFo84T | €0,30 |
| | | | **Total** | **X** |

> You can download the [Anemone Tentacle parts list as CSV file](TODO) or as [PDF file](TODO).
 
### Tools

Regarding the tools needed, we would recommend the following:

* Soldering station (for example Hakko TODO number)
* Leadless soldering iron
* Fizzlers
* Third hand

### Minimal Tentacle

> If you plan to use Tentacle readonly, there is a way to build what we call "a minimal Tentacle". Which is a striped version of Tentacle which consist only from Arduino YÚN, TFT display and *cloud button*.

With minimal Tentacle, you will not be able to use Tentacle fully, but it is enought to use it in readonly mode. And it still retains the share to guests functionality.

TODO image with all minimal Tentacle parts

#### Minimal Tentacle Parts List

TODO table

> You can download the [Minimal Tentacle parts list as CSV file](TODO) or as [PDF file](TODO).

## Step 2 - Build Tentacle electronic circuits

TODO...

## Step 3 - 3D print Tentacle case

Next step is to 3D print the *Anemone Tentacle case*.

> Anemone Tentacle case is in fact the very **first 3D printed Arduino YÚN case which is using the Arduino TFT Display** in the world! An it can be used even outside of the Anemone Platform. Feel free to use it even for your other projects ;).

TODO image 3D model wired

TODO image 3D model shaded

TODO image 3D model rendered

TODO image 3D model in blender

TODO image 3D model in slic3r - part1 - walls

TODO image 3D model in slic3r - part2 - bottom and insides

TODO image 3D model in slic3r - part3 - top and display covers

> You can find this part of our tutorial on a separate page as well. If you just need to print the Anemone Tentacle 3D case, see [How to print Anemone Tentacle Case](https://github.com/ceskasporitelna/anemone/blob/master/documentation/HowToPrintAnemoneTentacleCase.md).

## Step 4 - Assemble Tentacle

TODO image with all parts ready for assembly

TODO image with Tentacle without a case

TODO image with Tentacle in a case

TODO image with assembled Tentacle without top cover

TODO image with assembled Tentacle with top cover

## Step 5 - Install Tentacle software

Before connecting your Arduino ÝUN to the USB for the first time and following instructions in this tutorial, **we strongly recomend you read the following parts of the official documentation** from Arduino:

* https://www.arduino.cc/en/Main/ArduinoBoardYun
* https://www.arduino.cc/en/Guide/ArduinoYun

TODO https://www.arduino.cc/en/Tutorial/YunSysupgrade

TODO

## Step 6 - Connect Tentacle to Anemone Cloud

TODO

## Step 7 - *(Optional)* Install the "Juicy Day" example Anemone App on Tentacle

TODO

## What next?

When you have your Tentacle up and ready and you have played with the example app *Juicy Day*, you should read the [How to make Anemone App](https://github.com/ceskasporitelna/anemone/blob/master/documentation/HowToMakeAnemoneApp.md) tutorial and **make your first very own Anemone App**.

In general, do not miss the following:

1. [Anemone Overview](https://github.com/ceskasporitelna/anemone)
2. [Sign up](http://www.anemone.cloud/users/sign_up) for free and [download the Mobile Client](http://www.anemone.cloud)
3. Read the [How to make Anemone App](https://github.com/ceskasporitelna/anemone/blob/master/documentation/HowToMakeAnemoneApp.md) tutorial
4. Read the [How to make Anemone Connector](https://github.com/ceskasporitelna/anemone/blob/master/documentation/HowToMakeAnemoneConnector.md) tutorial
5. You may be also interested in the [Anemone Apps Repository](https://github.com/ceskasporitelna/anemone/tree/master/apps), [List of available Anemone Connectors](https://github.com/ceskasporitelna/anemone/tree/master/connectors) and [Anemone Arduino Library documentation](https://github.com/ceskasporitelna/anemone/tree/master/toolkit/anemone-arduino-library)
6. Explore the "Juicy Day" [example Anemone App on our GitHub](https://github.com/ceskasporitelna/anemone/tree/master/apps/juicy-day)
7. Write us. Tweet about us, write on Facebook, make a blogpost. Use hashtag **#anemoneCloud**.