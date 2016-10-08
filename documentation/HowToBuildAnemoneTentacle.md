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

In order to build a Tentacle you will need the following active components:

* 1x [Arduino YÚN](https://www.arduino.cc/en/Main/ArduinoBoardYun)
* 1x [Arduino TFT LCD Display](https://www.arduino.cc/en/Main/GTFT)
* 1x [Rotary Encoder KY-040](http://henrysbench.capnfatz.com/henrys-bench/arduino-sensors-and-input/keyes-ky-040-arduino-rotary-encoder-user-manual/) (used as a *menu knob*)
* 1x [Buzzer YL-44](https://rydepier.wordpress.com/2015/05/24/active-buzzer-alarm/)
* 1x [Microswitch TC-0108-T](https://www.gmelectronic.com/tc-0108-t) (used as a *cloud button*)
* 1x [Red Switch P-PB303B](https://www.gmelectronic.com/p-pb303b-red) (used as a *back button*)
* 2x [Green Super Flux LED 913PG2C](https://www.gmelectronic.com/super-flux-led-sfl-pure-green-2000-110-130) (used as a *back button backlight*)
* 2x [Optocoupler BPC-817C](https://www.gmelectronic.com/bpc-817c) *(or similar working with 5V input/output voltage)*
* 2x Resistor 220 Ohm
* 2x Resistor 10 Kiloohm

TODO image with all parts

And the following passive parts:

* 1x [Prototype Shield with Small Breadboard](https://goo.gl/QiYypK)
* 1x [Stripboard Single Side PCB 5x7cm](https://goo.gl/bP6dKk)
* 1x [RJ-11 Connector Box WEBP 6-4 LP 833-045](https://goo.gl/kE05f0) *(for I2C bus output)*
* 1x [Insulated wire on coil 0,4mm/25m Blue](https://goo.gl/lk7bCX)
* 1x [Breadboard Connectors PROSKIT OP-E351](https://goo.gl/8ECFLD)
* 1x [Female Headers Row 40](https://goo.gl/bsTJQJ)
* 1x [Male Headers Row 20 Straight](https://goo.gl/MwZm9u)
* 1x [Male Headers Row 20 90-deg](https://goo.gl/N3jrON)
* 15x [Jumper Wire M-F 10cm](https://goo.gl/9HJ0Yd)
* 10x [Jumper Wire M-M 10cm](https://goo.gl/9HJ0Yd)
* 3x [Jumper Wire M-F 20cm](https://goo.gl/QxP5vw)

TODO image with cable parts

### Parts List

In order to make your life easier we have prepared a list of links where you can buy all the Tentacle parts:

> This is just a hint ;). All the parts are **Open Hardware** you can buy them in your favourite shop, local hardware store, etc. 

| # | Part | Where to buy in Czech Republic* | Where to buy Worldwide |  Cost |
|:------------- |:------------- |:---------------:|:-------------:| -------------:|
| 1x | Arduino YÚN | https://goo.gl/WWNbBz | https://goo.gl/zxKTJE | €68.20 |
| 1x | Arduino TFT LCD Display | https://goo.gl/UJ5RQx | https://goo.gl/QMAZtW | €20.90 |
| 1x | Rotary Encoder KY-040 | https://goo.gl/HBKuvv | https://goo.gl/aWtrAF | €0.50 |
| 1x | Buzzer YL-44 | https://goo.gl/Eo4EEE | https://goo.gl/2WzGYW | €0.43 |
| 1x | Microswitch TC-0108-T | https://goo.gl/ncyT34 | https://goo.gl/iff8Z7 | €0.13 |
| 1x | Red Switch P-PB303B | https://goo.gl/mJq2Rl | https://goo.gl/SXAANZ | €0.45 |
| 2x | Green Super Flux LED 913PG2C | https://goo.gl/e5RzAD | https://goo.gl/xWg07e | €0.40 |
| 2x | Optocoupler BPC-817C | https://goo.gl/SSWsRn | https://goo.gl/BFo84T | €0.30 |
| 2x | Resistor 220 Ohm | - | - | 
| 2x | Resistor 10 Kiloohm | - | - | 
| 1x | Prototype Shield with Small Breadboard | https://goo.gl/Pvyxjw | https://goo.gl/QiYypK | €1.00 |
| 1x | Stripboard Single Side PCB 5x7cm | https://goo.gl/zTTTuU | https://goo.gl/bP6dKk | €1.26 |
| 1x | RJ-11 Connector Box WEBP 6-4 LP 833-045 | https://goo.gl/p4YbLA | https://goo.gl/kE05f0 | €0.25 |
| 1x | Insulated wire on coil 0,4mm/25m Blue | https://goo.gl/AbCSSo | https://goo.gl/lk7bCX | €2.20 |
| 1x | Breadboard Connectors PROSKIT OP-E351 | https://goo.gl/OA5zfP | https://goo.gl/8ECFLD | €12.29 |
| 1x | Female Headers Row 40 | https://goo.gl/Ps4XRd | https://goo.gl/bsTJQJ | €0.34 |
| 1x | Male Headers Row 20 Straight | https://goo.gl/Dz5Kux | https://goo.gl/MwZm9u | €0.23 |
| 1x | Male Headers Row 20 90-deg | https://goo.gl/94bT0B | https://goo.gl/N3jrON | €0.34 |
| 1x | Jumper Cables M-M, M-F, F-F, 40pcs, 10cm | https://goo.gl/WffkiF | https://goo.gl/9HJ0Yd | €3.45 |
| 1x | Jumper Cables M-M, M-F, F-F, 40pcs, 20cm | https://goo.gl/buLGLN | https://goo.gl/QxP5vw | €2.17 |
| | | | **Total** | **€114,84** |

**The Anemone platform (as well as the Tentacle) has been developed with love in [Prague](https://goo.gl/maps/gx7orLWymPA2), so people from our country have special buying options column ;)*

> You can download the [Anemone Tentacle parts list as CSV file](TODO) or as [PDF file](TODO).
 
### Tools

Regarding the tools needed, we would recommend the following:

* Soldering station *(for example [Hakko FX-888D](https://www.hakko.com/english/products/hakko_fx888d.html))*
* Leadless soldering iron
* Tweezers *(for example a [set from VETUS](https://www.aliexpress.com/wholesale?catId=0&SearchText=vetus+tweezers+6pcs))*
* [Third hand soldering iron stand](https://www.aliexpress.com/wholesale?catId=190405&SearchText=third+hand+soldering)

### Minimal Tentacle (optional)

> If you plan to use Tentacle just readonly, there is a way to build what we call "a minimal Tentacle". Which is a striped version of Tentacle which consist only from Arduino YÚN, TFT display and a *cloud button*.

TODO image if wiring of minimal Tentacle

With minimal Tentacle, you will not be able to use Tentacle fully, but it is enought to use it in readonly mode. And it still retains the share to guests functionality.

TODO image with all minimal Tentacle parts

For a minimal Tentacle, you will need the following:

> A minimal Tentacle is NOT compatible with the 3D printed Anemone Tentacle case (the case assumes that you have the original Anemone Tentacle, hence in case of minimal Tentacle, you will miss many parts).

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

TODO final Anemone Tentacle printed and running

> You can find this part of our tutorial on a separate page as well. If you just need to print the Anemone Tentacle 3D case, see [How to print Anemone Tentacle Case](https://github.com/ceskasporitelna/anemone/blob/master/documentation/HowToPrintAnemoneTentacleCase.md).

### 3D model 

The Anemone Tentacle 3D model has been created in Blender and if you like you can download the original [.blend file](TODO).

But we have provided [.stl exports](TODO) for you as well.

TODO image 3D model in blender

Anemone Tentacle case consists of the following parts:

TODO image with arrows and part names

### Slicing

The Anemone Tentacle 3D case is available either as [.stl files of 9 individual components](TODO):

* The Bottom Part
* The Walls
* The Top Button
* The Top Button Lodge
* The Top Button Lever
* The Menu Knob Cover
* The Front Button
* The Top (LEGO® compatible) cover
* The Front Display Frame

Or as three [*ready-to-print* .stl files](TODO) with all components assigned into three groups *(with slightly different print settings)* :

1. Bottom and Insides
2. Walls
3. Top and Display covers

> In addition to the [.stl *ready-to-print* file for every print group](TODO) you can download a exported [gcode files for the *Prusa i3 MK2 3D Printer* with ABS filament setting](TODO). We have use these gcode files to print our version of Anemone Tentacle on *Kanárek*. 

#### Bottom and Insides

TODO image 3D model in slic3r - part1 - bottom and insides

The first print group consists of case bottom part, internal components and all knobs and buttons.

#### Walls

TODO image 3D model in slic3r - part2 - walls

The second print group is the case walls.

#### Top and Display covers

TODO image 3D model in slic3r - part3 - top and display covers

The last print group contains the top LEGO® compatible cover piece and display frame cover.

### Recommended print settings

The Anemone Tentacle case is optimized **to be printed in ABS** *(but theoretically should print well with PLA too)*.

We have used the [Slic3r](http://slic3r.org/) for slicing the `.stl` files into `.gcode`.

> Anemone Tentacle case looks awesome even on low print settings - which looks nice with a semi-transparent filament.

#### Global settings

* Filament: **ABS 1.75mm**
* Extruder Temperature: **255°C**
* Heatbed Temperature: **100°C**
* Layer height: **0.35mm**
* First layer height: **0.15mm**
* Perimeters: **1**
* Infill density: **15%**
* Infill pattern: **Honeycomb**
* Skirt: **1**
* Brim: **0mm**
* Support: **No**

#### Detailed settings

Detailed settings are slightly different for each of the three recommended print groups **(only the attributes different from the global settings are shown)**:

1. Bottom and Insides
	* Infill density: **20%** 
2. Walls
	* Brim: **5mm**
	* Support: **Yes**
	* Support Pattern: **Pillars**
3. Top and Display covers
	* Infill density: **20%** 
	* Perimeters: **5**

### Tips and Tricks

* When printing with ABS you HAVE TO to use the heated bed!
* The second print group (The Walls) **needs to have brim** which helps the print to stay connected to bed and not bend while printing (we use 5mm).
* The second print group (The Walls) **needs to be printed with supports** (we recommend **pillars** type if you use [Slic3r](http://slic3r.org/)).
* Best infill type is Honeycomb with 15% density for The Walls part which even helps to achieve the nice light reflecting effects with a semi-transparent filament.

### How it looks 3D printed

> Example print shown on the images below was printed on our *"Kanárek"* 3D printer which is a [Prusa i3 MK2 3D Printer](http://www.prusa3d.com/#our-printer) using the semitransparent [blue EasyABS-T filament](http://shop.prusa3d.com/en/filament/57-blue-easyabs-filament-1kg.html). We recomend this filament, even with a low print settings the resulting light effects looks just awesome!

TODO printed tentacle 4 IMAGES

Because the top of the Anemone Tentacle is LEGO® compatible, you can customize your Tentacle to fit your desires with the world most famous building kit.

TODO 2 Tentacle images with LEGO build on them

## Step 4 - Assemble Tentacle

TODO image with all parts ready for assembly

TODO image with Tentacle without a case

TODO image with Tentacle in a case

TODO image with assembled Tentacle without top cover

TODO image with assembled Tentacle with top cover

TODO assembly video

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

LEGO® is a trademark of the LEGO Group of companies which does not sponsor, authorize or endorse this site ([trademark guidelines](http://www.lego.com/en-us/legal/legal-notice/fair-play)).