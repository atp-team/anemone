# How to build Anemone Tentacle

Anemone Tentacle is a DIY Open Hardware device you can build and 3D print a cute case for it.

> Tentacle is fully Open Hardware device based on Arduino YÚN and Arduino TFT Display. It can be used as part of [Anemone Platform](http://www.anemone.cloud) or completelly standalone as a nice case for Arduino YÚN and Arduino TFT display.

## How Tentacle looks like?

![Anemone Tentacle 3D Visualization](http://i.makeagif.com/media/10-20-2016/-5jEft.gif)

> Video in better quality can be seen at [youtube](https://youtu.be/jqXTOFYfvtk).

<img class="icon" alt="Anemone Tentacle - Render from right" src="https://github.com/ceskasporitelna/anemone/blob/master/documentation/images/renders/alpha/blur_tentacle_right.png?raw=true" width="300"> <img class="icon" alt="Anemone Tentacle - Render from left" src="https://github.com/ceskasporitelna/anemone/blob/master/documentation/images/renders/alpha/blur_tentacle_left.png?raw=true" width="300">

<img class="icon" alt="Anemone Tentacle - Printed and assembled from left" src="https://github.com/ceskasporitelna/anemone/blob/master/documentation/images/assembled_tentacle/0_assembled_tentacle_alpha_left.png?raw=true" height="300"> <img class="icon" alt="Anemone Tentacle - Printed and assembled from right" src="https://github.com/ceskasporitelna/anemone/blob/master/documentation/images/assembled_tentacle/0_assembled_tentacle_alpha_right.png?raw=true" height="300">

Tentacle has three hardware controls which you can see on the following image:

<img class="icon" alt="Anemone Tentacle - Interactive parts" src="https://github.com/ceskasporitelna/anemone/blob/master/documentation/images/renders/tentacle_interactive_parts.png?raw=true" width="300">

> The interactive parts are shown in black color

* The **top button** is used as a *back button* by the [Anemone arduino library](https://github.com/ceskasporitelna/anemone/tree/master/toolkit/anemone-arduino-library), but can be used in your Anemone apps as well
* The **side knob** is used as a *menu button & controller* and should not be used for any other purpose than a menu trigger and navigation
* The **front button** is used as a *cloud button* by the Anemone arduino library and it should not be used in your Anemone app at all *(the user should always have the ability to switch Tentacle to the share mode - without caring about where in your Anemone app he is currently present)*

> Of course these limitations/recomendations apply only when you use the Tentacle inside the [Anemone Platform](http://www.anemone.cloud) with the [Anemone arduino library](https://github.com/ceskasporitelna/anemone/tree/master/toolkit/anemone-arduino-library). When using the Tentacle outside of the Anemone ecosystem, feel free to repurpose all the buttons as you see fit.

## That is nice! How to build it?

In this tutorial we will guide you through the Tentacle building process.

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

* 1x [Arduino YÚN](https://www.arduino.cc/en/Main/ArduinoBoardYun) *(+ SD card)*
* 1x [Arduino TFT LCD Display](https://www.arduino.cc/en/Main/GTFT) *(+ SD card)*
* 1x [Rotary Encoder KY-040](http://henrysbench.capnfatz.com/henrys-bench/arduino-sensors-and-input/keyes-ky-040-arduino-rotary-encoder-user-manual/) (used as a *menu knob*)
* 1x [Buzzer YL-44](https://rydepier.wordpress.com/2015/05/24/active-buzzer-alarm/)
* 1x [Microswitch TC-0108-T](https://www.gmelectronic.com/tc-0108-t) (used as a *cloud button*)
* 1x [Red Switch P-PB303B](https://www.gmelectronic.com/p-pb303b-red) (used as a *back button*)
* 2x [Green Super Flux LED 913PG2C](https://www.gmelectronic.com/super-flux-led-sfl-pure-green-2000-110-130) (used as a *back button backlight*)
* 2x [Optocoupler BPC-817C](https://www.gmelectronic.com/bpc-817c) *(or similar working with 5V input/output voltage)*
* 2x Resistor 220 Ohm
* 2x Resistor 10 Kiloohm

<img class="icon" alt="Anemone Tentacle - Needed parts" src="https://github.com/ceskasporitelna/anemone/blob/master/documentation/images/tentacle_all_parts.jpg?raw=true" width="600">

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

<img class="icon" alt="Anemone Tentacle - Needed wires" src="https://github.com/ceskasporitelna/anemone/blob/master/documentation/images/tentacle_wire_parts.jpg?raw=true" width="300"> <img class="icon" alt="Anemone Tentacle - Needed tools" src="https://github.com/ceskasporitelna/anemone/blob/master/documentation/images/tentacle_passive_parts.jpg?raw=true" width="300">

### Parts List

In order to make your life easier we have prepared a list of links where you can buy all the Tentacle parts:

> This is just a hint ;). All the parts are **Open Hardware** you can buy them in your favorite shop, local hardware store, etc. 

| # | Part | Where to buy in Czech Republic* | Where to buy Worldwide | Cost |
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
| | | | **Total** | **€114.84** |

**The Anemone platform (as well as the Tentacle) has been developed with love in [Prague](https://goo.gl/maps/gx7orLWymPA2), so people from our country have special buying options column ;)*

> You can download the [Anemone Tentacle parts list as CSV file](https://github.com/ceskasporitelna/anemone/blob/master/documentation/files/anemone-tentacle-parts.csv) or as [PDF file](https://github.com/ceskasporitelna/anemone/blob/master/documentation/files/anemone-tentacle-parts.pdf).
 
### Tools

Regarding the tools needed, we would recommend the following:

* Soldering station *(for example [Hakko FX-888D](https://www.hakko.com/english/products/hakko_fx888d.html))*
* Leadless soldering iron
* Tweezers *(for example a [set from VETUS](https://www.aliexpress.com/wholesale?catId=0&SearchText=vetus+tweezers+6pcs))*
* [Third hand soldering iron stand](https://www.aliexpress.com/wholesale?catId=190405&SearchText=third+hand+soldering)
* Cable insulation remover
* Knife
* Multi-Meter

<img class="icon" alt="Anemone Tentacle - Needed tools" src="https://github.com/ceskasporitelna/anemone/blob/master/documentation/images/tentacle_passive_parts.jpg?raw=true" width="300">

### Minimal Tentacle (optional)

> If you plan to use Tentacle just readonly, there is a way to build what we call "a minimal Tentacle". Which is a striped version of Tentacle which consist only from Arduino YÚN, TFT display and a *cloud button*.

<img class="icon" alt="Anemone Minimal Tentacle - Wiring" src="https://github.com/ceskasporitelna/anemone/blob/master/documentation/images/anemone_tentacle_minimal_breadboard.png?raw=true" width="300"> <img class="icon" alt="Anemone Minimal Tentacle - Wiring" src="https://github.com/ceskasporitelna/anemone/blob/master/documentation/images/anemone_tentacle_minimal_scheme.png?raw=true" width="300">

With minimal Tentacle, you will not be able to use Tentacle fully, but it is enought to use it in readonly mode. And it still retains the share to guests functionality.

<img class="icon" alt="Anemone Minimal Tentacle - Needed parts" src="https://github.com/ceskasporitelna/anemone/blob/master/documentation/images/tentacle_minimal_parts.jpg?raw=true" width="300">

For a minimal Tentacle, you will need the following:

> A minimal Tentacle is NOT compatible with the 3D printed Anemone Tentacle case (the case assumes that you have the original Anemone Tentacle, hence in case of minimal Tentacle, you will miss many parts).

#### Minimal Tentacle Parts List

| # | Part | Where to buy in Czech Republic* | Where to buy Worldwide | Cost |
|:------------- |:------------- |:---------------:|:-------------:| -------------:|
| 1x | Arduino YÚN | https://goo.gl/WWNbBz | https://goo.gl/zxKTJE | €68.20 |
| 1x | Arduino TFT LCD Display | https://goo.gl/UJ5RQx | https://goo.gl/QMAZtW | €20.90 |
| 1x | Microswitch TC-0108-T | https://goo.gl/ncyT34 | https://goo.gl/iff8Z7 | €0.13 |
| 1x | Optocoupler BPC-817C | https://goo.gl/SSWsRn | https://goo.gl/BFo84T | €0.30 |
| 1x | Resistor 220 Ohm | - | - | 
| 1x | Resistor 10 Kiloohm | - | - | 
| 1x | Jumper Cables M-M, M-F, F-F, 40pcs, 20cm | https://goo.gl/buLGLN | https://goo.gl/QxP5vw | €2.17 |
| | | | **Total** | **€91.70** |

> You can download the [Minimal Tentacle parts list as CSV file](https://github.com/ceskasporitelna/anemone/blob/master/documentation/files/minimal-tentacle-parts.csv) or as [PDF file](https://github.com/ceskasporitelna/anemone/blob/master/documentation/files/minimal-tentacle-parts.pdf).

## Step 2 - Build Tentacle electronic circuits

The Anemone Tentacle electronic circuit has the following scheme:

<img class="icon" alt="Anemone Tentacle - Electrical Circuit Scheme" src="https://github.com/ceskasporitelna/anemone/blob/master/documentation/images/anemone_tentacle_prototype_scheme.png?raw=true" width="600">

The **simplified** wiring image looks like this:

> In order to let you understand the Tentacle wiring better, we have created a simplified wiring image. In this image we have **removed all passive components** *(like a prototype shield or stripboard)* and have replaced them by a classic breadboard.
 
<img class="icon" alt="Anemone Tentacle - Simplified Electrical Circuit Wiring" src="https://github.com/ceskasporitelna/anemone/blob/master/documentation/images/anemone_tentacle_prototype_breadboard.png?raw=true" width="600">

In addition we have created an image where the `VCC` (5V) is shown as a **Red wire**, VCC (3.3V) is shown as a **Pink wire** and `GND` as a **Black wire**.

<img class="icon" alt="Anemone Tentacle - Simplified Electrical Circuit Wiring VCC GND" src="https://github.com/ceskasporitelna/anemone/blob/master/documentation/images/anemone_tentacle_prototype_breadboard_VCC_GND.png?raw=true" width="600">

The final *(not simplified)* wiring of a Tentacle then looks like this:

<img class="icon" alt="Anemone Tentacle - Electrical Circuit Wiring" src="https://github.com/ceskasporitelna/anemone/blob/master/documentation/images/anemone_tentacle_breadboard.png?raw=true" width="600">

And this is how Tentacle looks like this when assembled *(without the case)*:

TODO assemled Tentacle image

> These assebled electrical circuits should the be put inside the *Anemone Tentacle Case* which is described later below.

Below we will explain the Anemone Tentacle wiring construction **step by step**.

### Step 2.1 - Introduction

Before we move further, in order to avoid confusion, lets explain how some components shown on our breadboard wiring image look like in reality.

#### Buzzer YL-44

The *Buzzer YL-44* looks like this.

<img class="icon" alt="Anemone Tentacle - Where buzzer YL-44 is o the wiring image" src="https://github.com/ceskasporitelna/anemone/blob/master/documentation/images/compilation_buzzer.png?raw=true" width="600">

#### Rotary Encoder KY-040

The *Rotary Encoder KY-040* looks like this.

<img class="icon" alt="Anemone Tentacle - Where buzzer YL-44 is o the wiring image" src="https://github.com/ceskasporitelna/anemone/blob/master/documentation/images/compilation_encoder.png?raw=true" width="600" border="1">

#### Arduino Prototype Shield

The grey wires mess is in fact the *Arduino Prototype Shield* pluged to Arduino YÚN.

<img class="icon" alt="Anemone Tentacle - Where buzzer YL-44 is o the wiring image" src="https://github.com/ceskasporitelna/anemone/blob/master/documentation/images/compilation_tentacle_shield.png?raw=true" width="600">

#### RJ-11 I2C Bus Socket

The RJ-11 socket is used as an output for I2C bus.

<img class="icon" alt="Anemone Tentacle - Where buzzer YL-44 is o the wiring image" src="https://github.com/ceskasporitelna/anemone/blob/master/documentation/images/compilation_i2c.png?raw=true" width="600">

#### Arduino TFT Display

What looks like some Adafruit Display is in fact the original *Arduino TFT Display*. We were just not able to find better part in Fritzing for it.

<img class="icon" alt="Anemone Tentacle - Where buzzer YL-44 is o the wiring image" src="https://github.com/ceskasporitelna/anemone/blob/master/documentation/images/compilation_tft.png?raw=true" width="600">

And the rest is as it seems to be. A few resistors, optocouplers, buttons and LEDs.

### Step 2.2 - *Plug-and-Play* components preparation

In order to make the Tentacle assemble as easy as is possible, the best way how to put it together is to first prepare what we call "*Plug-and-Play components*" and then put them together.

> This approach will play well with the cute 3D printed case for your Tentacle (if you plan to use it).

#### Step 2.2.1 - Prototype Shield Legs

As any Arduino out there the *Arduino YÚN* is compatible with **Arduino shields** *(aka boards with additional electronic circuits which can extend capabilities of your Arduino)*.

Which is exactly what we are going to do - we will extend capabilities of our Arduino YÚN by creating and later pluging into it **an Anemone Tentacle Shield**.

There is just one issue with the idea (and shields on Arduino YÚN in general) - Arduino YÚN **does not conform** to the default height of its electronic components which is exepected by the majority of Arduino shields because it features an ethernet socked which height is too large. This means that any shield you plan to use on your Arduino YÚN needs to have longer "legs" (aka pin headers).

And this is exactly the thing we need to do with our **Anemone Tentacle Shield**.

The Anemone Tentacle Shield will be based on the *Arduino Prototype Shield*.

TODO image of arduino prototype shield

Hence the first step is creation of longer legs for our shield.

In general there are two ways how you can achieve it.

1. You can de-solder the original legs on the shield and replace them with longer ones
2. Or you can build a reduction (aka something you will put between the short legs of shield and short sockets of Arduino YÚN in order to make the legs longer)

> We strongly recomend you to follow the option 2.
 
The reason is, that option 1. is **much more complicated**. First you need to own a de-soldering machine in order to be able to de-solder anything *(especially parts with more than one connection are nearly impossible to be de-soldered using a classic soldering tool)*. Second reason is that longer legs (aka jumper wire headers) are much more difficult to buy that the classic ones which you can always order from China.

So we have taken option 2. The result looks like this.

TODO image of legs

The legs can be the connected to our *Anemone Tentacle Shield*.

TODO image of legs connected to the shield.

Which can be then connected to the Arduino YÚN.

TODO image of shield connected to yun

#### Step 2.2.2 - Display Board

With the *Anemone Tentacle Shield* legs done we can move to the **Display Board** assembly.

TODO display board without components image

The **Display Board** is a very important component of the Anemone Tentacle. Its purpose is to hold the *Arduino TFT Display*, the *YL-44 Buzzer* and the *Cloud Button* together and to provide *an easy-wiring solution* of these components to the rest of the Tentacle.

The *Display Board* is based on a **Stripboard Single Side PCB 5x7cm**.

TODO empty stripboard image

On the **top side** of the stripboard we will solder the following:

1. Two lines of Jumper Wire Header Sockets which will hold the Arduino TFT Display
2. One line of 90-deg. Jumper Wire Headers which will be our connection point to the rest of the Tentacle
3. One button which will serve as the Cloud Button 
4. The YL-44 Buzzer (attached to Display Board using *hot glue*)

TODO image of top side of display board

On the **bottom side** of the stripboard we will create connections between the components. These should look like this.

TODO image of bottom side of display board

As a next step we will attach a *20cm jumper cable F-M* to the *YL-44 Buzzer*.

TODO image of display board with wire to buzzer

And next step is attaching a *10cm jumper cable F-M* to the *90-deg. Jumper Wire Headers* which will connect the Cloud Button and TFT Display to the rest of the Tentacle.

TODO image of display board with both wires

And the finale step is to attach the Arduino TFT Display *(with SD card)* to its sockets.

TODO image of completed display board

#### Step 2.2.3 - Tentacle Shield Wiring

#### Step 2.2.4 - Arduino YÚN SPI Wiring

#### Step 2.2.5 - Rotary Encoder KY-040 Wiring

#### Step 2.2.6 - Top Button Wiring

#### Step 2.2.7 - Top LEDs Wiring

#### Step 2.2.8 - I2C RJ-11 Socket Wiring

The RJ-11 socket which will be used for I2C bus looks like this when prepared to be wired:

<img alt="Anemone Tentacle - I2C RJ-11 Socket prepared to be wired" src="https://github.com/ceskasporitelna/anemone/blob/master/documentation/images/tentacle_i2c.jpg?raw=true" width="300">

### Step 2.3 - Tentacle electronic circuits assembly

#### Step 2.3.1 - Tentacle Shield

The Tentacle electronic circuits assembly starts with the **Tentacle Shield** we have prepared in *step 2.2.3*.

<img alt="Anemone Tentacle - Assembly step 1 - Tentacle Shield" src="https://github.com/ceskasporitelna/anemone/blob/master/documentation/images/anemone_tentacle_build_1_tentacle_shield.png?raw=true" width="600">

TODO add photo for step 1

#### Step 2.3.2 - Arduino YÚN

Next step is to connect the **Tentacle Shield** to **Arduino YÚN** with the headers (or legs) we have prepared in *step 2.2.1*.

> Wires shown as **banded** are those you should add in this step.

<img alt="Anemone Tentacle - Assembly step 2 - Arduino YÚN" src="https://github.com/ceskasporitelna/anemone/blob/master/documentation/images/anemone_tentacle_build_2_yun.png?raw=true" width="600">

TODO add photo for step 2

#### Step 2.3.3 - SPI from Arduino YÚN ICSP

Next step is to wire **SPI bus from Arduino YÚN** ICSP headers to the breadboard on the *Tentacle Shield*.

> Wires shown as **banded** are those you should add in this step.

<img alt="Anemone Tentacle - Assembly step 3 - SPI from Arduino YÚN ICSP" src="https://github.com/ceskasporitelna/anemone/blob/master/documentation/images/anemone_tentacle_build_3_icsp_wire.png?raw=true" width="600">

TODO add photos for step 3

#### Step 2.3.4 - Back Button

Next step is to wire **the Back Button** to the breadboard on the *Tentacle Shield*.

> Wires shown as **banded** are those you should add in this step.

<img alt="Anemone Tentacle - Assembly step 4 - Back Button" src="https://github.com/ceskasporitelna/anemone/blob/master/documentation/images/anemone_tentacle_build_4_back_button.png?raw=true" width="600">

TODO add photo for step 4

#### Step 2.3.5 - Rotary Encoder

Next step is to wire **the Rotary Encoder KY-040** to the *Tentacle Shield*.

> Wires shown as **banded** are those you should add in this step.

<img alt="Anemone Tentacle - Assembly step 5 - Rotary Encoder" src="https://github.com/ceskasporitelna/anemone/blob/master/documentation/images/anemone_tentacle_build_5_rotary_encoder.png?raw=true" width="600">

TODO add photo for step 5

#### Step 2.3.6 - RJ-11 I2C Socket

Next step is to wire **RJ-11 I2C Socket** to the breadboard on the *Tentacle Shield*.

<img alt="Anemone Tentacle - Assembly step 5.5 - RJ-11 I2C Socket Board" src="https://github.com/ceskasporitelna/anemone/blob/master/documentation/images/anemone_tentacle_build_5_5_rj11_i2c_board.png?raw=true" width="600">

> Wires shown as **banded** are those you should add in this step.

<img alt="Anemone Tentacle - Assembly step 6 - RJ-11 I2C Socket" src="https://github.com/ceskasporitelna/anemone/blob/master/documentation/images/anemone_tentacle_build_6_rj11_i2c.png?raw=true" width="600">

> As you may have already noticed, the wires from the RJ-11 socket **are currently not connected to anything on the breadboard**. We know about this and this is something what needs to be solved in future *(or what can be solved by you!)*. One possibility is to connect the wires directly to the A5 and A4 analog inputs of the Arduino YÚN *(aka I2C bus interface)* and to the VCC and GND. That will give a direct access to the I2C interface via the RJ-11 connector.
> 
> But we initally wanted to make this I2C output compatible with the *LEGO® MindStorms kit*. And that is possible but it **requires two additional pull-up resitors and some wiring**, hence the connection is not trivial and **we did not wanted to make the Tentacle more complex just for a feature which might be used by less then 10% of users**. 
> 
> That is why we have decided to left this feature for you to finish it in a way which serves best your needs. Feel free to connect the I2C interface either in a classic way, or via the *LEGO® MindStorms* compatible way.
> 
> A detailed instructions how to connect Arduino to *LEGO® MindStorms* I2C interface can be found [here](http://www.dexterindustries.com/howto/connect-the-arduino-and-the-lego-mindstorms-together/).

TODO add photo for step 6

#### Step 2.3.7 - Top LEDs

Next step is to wire **the Top LEDs** to the breadboard on the *Tentacle Shield*.

> Wires shown as **banded** are those you should add in this step.

The blue wire is `GND`.

<img alt="Anemone Tentacle - Assembly step 7 - Top LEDs" src="https://github.com/ceskasporitelna/anemone/blob/master/documentation/images/anemone_tentacle_build_7_top_leds.png?raw=true" width="600">

TODO add photo for step 7

#### Step 2.3.8 - Buzzer

Next step is to wire **the Buzzer from the Display Board** to the *Tentacle Shield*.

First put the **Display Board** next to your **Tentacle**.

<img alt="Anemone Tentacle - Assembly step 7.5 - Display Board" src="https://github.com/ceskasporitelna/anemone/blob/master/documentation/images/anemone_tentacle_build_7_5_display_board.png?raw=true" width="600">

And then wire **the Buzzer**

> Wires shown as **banded** are those you should add in this step.

The grey wire is `VCC`.

<img alt="Anemone Tentacle - Assembly step 8 - Buzzer" src="https://github.com/ceskasporitelna/anemone/blob/master/documentation/images/anemone_tentacle_build_8_buzzer.png?raw=true" width="600">

TODO add photos for step 8

#### Step 2.3.9 - Cloud Button

Next step is to wire **the Cloud Button from the Display Board** to the breadboard on the *Tentacle Shield*.

> Wires shown as **banded** are those you should add in this step.

The green wire is `VCC`.

<img alt="Anemone Tentacle - Assembly step 9 - Cloud Button" src="https://github.com/ceskasporitelna/anemone/blob/master/documentation/images/anemone_tentacle_build_9_cloud_button.png?raw=true" width="600">

TODO add photos for step 9

#### Step 2.3.10 - TFT Display

Next step is to wire **the Arduino TFT Display from the Display Board** to the breadboard on the *Tentacle Shield*.

> Wires shown as **banded** are those you should add in this step.

The brown wire is `VCC`, the black wire is `GND`.

<img alt="Anemone Tentacle - Assembly step 10 - TFT Display" src="https://github.com/ceskasporitelna/anemone/blob/master/documentation/images/anemone_tentacle_build_10_lcd.png?raw=true" width="600">

TODO add photos for step 10

> That concludes the Anemone Tentacle electronic circuits assembly process. **Congratulations!**

Your Anemone Tentacle should now look like this:

<img alt="Anemone Tentacle - Assembly step 11 - Complete Tentacle Wiring" src="https://github.com/ceskasporitelna/anemone/blob/master/documentation/images/anemone_tentacle_build_11_done.png?raw=true" width="600">

When assembled the Tentacle electronic circuits looks like this (without the case):

<img alt="Anemone Tentacle - Assembled Electronic Circuits without case" src="https://github.com/ceskasporitelna/anemone/blob/master/documentation/images/assembled_tentacle_insides.jpg?raw=true" width="600">

> We recommend testing the Tentacle electronic circuits after inserting them into the bottom part of the **Anemone Tentacle Case** in the *Step 4*.

When put inside the bottom part of the case it looks like this:

TODO bottom tentacle part image with electronic circuits

> The Anemone Tentacle assembly instruction *(eg. how to put the electronic circuits into the 3D printed case)* are provided below.

## Step 3 - 3D print Tentacle case

Next step is to 3D print the *Anemone Tentacle case*.

> For the *How to print* Anemone Tentacle case refer to a separate page of our tutorial, see [How to print Anemone Tentacle Case](https://github.com/ceskasporitelna/anemone/blob/master/documentation/HowToPrintAnemoneTentacleCase.md).

## Step 4 - Assemble Tentacle

With the Anemone Tentacle case 3D printed and all electronic components assembled we can **approach the Anemone Tentacle assembly**.

### 4.1 Tentacle Components

Anemone Tentacle consists of the following components:

<img alt="Anemone Tentacle Parts Description Left" src="https://github.com/ceskasporitelna/anemone/blob/master/documentation/images/renders/numbered/left_big.png?raw=true" width="300"> <img alt="Anemone Tentacle Parts Description Right" src="https://github.com/ceskasporitelna/anemone/blob/master/documentation/images/renders/numbered/right_big.png?raw=true" width="300">

1. Top LEDs
2. Tentacle Shield
3. Arduino YÚN
4. Display Board
5. Cloud Button
6. Buzzer YL-44
7. Arduino TFT Display
8. Top Button
9. RJ-11 I2C Socket
10. Rotary Encoder KY-040

### 4.2 Preparation

First gather all the Tentacle parts on one place in front of you.

You will need all parts of the 3D printed case.

TODO image with all parts ready for assembly

And the assembled Tentacle electronic circuits.

TODO image with Tentacle without a case

### 4.3 Assembly

When assembled your Tentacle should look like this:

TODO image with Tentacle in a case

As a last step, you should add the Top Cover:

TODO image with assembled Tentacle without top cover

And your Tentacle is ready!

TODO image with assembled Tentacle with top cover

In order to make your life easier, we have create a video with shows the whole Tentacle assembly process.

TODO assembly video

## Step 5 - Install Tentacle software

Before connecting your Arduino ÝUN to the USB for the first time and following instructions in this tutorial, **we strongly recomend you read the following parts of the official documentation** from Arduino:

* https://www.arduino.cc/en/Main/ArduinoBoardYun
* https://www.arduino.cc/en/Guide/ArduinoYun

### Step 5.1 - Update Arduino YÚN OpenWRT image

We need to be sure to use the latest version of Arduino YÚN image. 
Follow the instructions on https://www.arduino.cc/en/Tutorial/YunSysupgrade to install latest OpenWRT image on your Arduino YÚN.

### Step 5.2 - Connect Arduino YÚN to Internet

As a next step, make sure that your Arduino YÚN is connected to the internet - either by Wi-Fi or Ethernet.

You can check if your Arduino YÚN is connected to Internet either from it's web control panel, or by SSHing to it and executing something like this:

```bash
ping www.google.com
```

or if you like you can verify connection to the *Anemone Cloud* by:

```bash
ping www.anemone.cloud
```

## Step 6 - Connect Tentacle to Anemone Cloud

> Please check if your Tentacle is connected to Internet **before advancing in the tutorial**. You will not be able to do this step without having your Arduino YÚN connected to the Internet.

### Step 6.1 - Sign up to the Anemone Cloud

Open the [Anemone Cloud Sign up page](http://www.anemone.cloud/users/sign_up) and perform a free registration.

<img alt="Anemone Cloud - Sign up" src="https://github.com/ceskasporitelna/anemone/blob/master/documentation/images/cloud_1_sign_up.png?raw=true" width="600">

### Step 6.2 - Create new Tentacle on Anemone Cloud

After signing up you will see (empty) *list of your Anemone apps* a.k.a **your dashboard**.

<img alt="Anemone Cloud - Dashboard" src="https://github.com/ceskasporitelna/anemone/blob/master/documentation/images/cloud_2_dashboard.png?raw=true" width="600">

You need to *press the New button* in the left menu under the *Tentacles* section.

<img alt="Anemone Cloud - Press New button in the left menu under the Tentacles section" src="https://github.com/ceskasporitelna/anemone/blob/master/documentation/images/cloud_3_open_add_tentacle_form.png?raw=true" width="600">

Now you should *fill your Tentacle name*.

<img alt="Anemone Cloud - Fill Tentacle name" src="https://github.com/ceskasporitelna/anemone/blob/master/documentation/images/cloud_4_fill_tentacle_name.png?raw=true" width="600">

And finaly press the *Add a new Tentacle* button.

<img alt="Anemone Cloud - Add a new Tentacle" src="https://github.com/ceskasporitelna/anemone/blob/master/documentation/images/cloud_5_add_tentacle.png?raw=true" width="600">

Your new Tentacle is *successfully created*. Nice job! ;)

<img alt="Anemone Cloud - Tentacle is created" src="https://github.com/ceskasporitelna/anemone/blob/master/documentation/images/cloud_6_tentacle_added.png?raw=true" width="600">

### Step 6.3 - Download `tentacle.sh` from Anemone Cloud

You can download the `tentacle.sh` initialization script **from the list of Tentacles** in your *Anemone Cloud Administration*.

Just click on the **"Download Arduino initializer script"** link *next ot your Tentacle* in the list.

> It is important to download the right *initializer script*! Every Anemone Tentacle has its own. Only owner of a Tentacle can download its *initializer script*. Guests are not allowed to do this.

<img alt="Anemone Cloud - Download tentacle.sh" src="https://github.com/ceskasporitelna/anemone/blob/master/documentation/images/cloud_7_download_init_script.png?raw=true" width="600">

### Step 6.4 - Run `tentacle.sh` on your Tentacle via SSH

Enter the folder where you have the downloaded the `tentacle.sh` and perform this command in terminal:

```bash
ssh root@tentacle.local 'sh -s' < tentacle.sh
```

> You will be asked to enter the Arduino YÚN password. The default password is `arduino`. And it can be changed in Arduino YÚN WebAdmin panel.

Where `tentacle.local` is your Tentacle (Arduino YÚN). We have named our Arduino YÚN *"Tentacle"* do it now has domain name `tentacle.local`.

> By default Arduino YÚN has domain name `arduino.local`. On Windows machines you might not be able to connect to your Arduino YÚN using its domain name. In that case, use its IP address instead.

You can find the IP address of your Arduino YÚN from its WebAdmin panel or by using the `nmap` cli tool:

```bash
nmap -sP 192.168.1.0/24
```

Where `192.168.1.0` is your network IP address.

> You can find your network IP address *usually* by taking your machine IP address and replace the last number with 0.

The Tentacle initialization script (`tentacle.sh`) will perform the following on your Tentacle:

1. It will install the Ruby programming language on your Tentacle (which is needed by the Linux part of the [Anemone Arduino Library](https://github.com/ceskasporitelna/anemone/tree/master/toolkit/anemone-arduino-library))
2. It will download all needed parts of the Anemone ecosystem from Anemone Cloud and install them on your Tentacle
3. It will perform the OTA update and install the Initial Anemone sketch to your Tentacle
4. It will register the newly created Tentacle with the Anemone Cloud

After these steps your Tentacle will be up and running.

<img alt="Anemone Tentacle UI - Ready for app installation" src="https://github.com/ceskasporitelna/anemone/raw/master/documentation/images/app_ready_for_installation.png">

> While running the Tentacle initialization script (`tentacle.sh`) is printing to the console what it is currently doing. So you can check its progress in the SSH console of your Tentacle.
> 
> Please be patient, the **Arduino YÚN is a very slow device** and the first Tentacle initialization **can take up to 40 minutes**.
> 
> In case of problems or questions, please refer the [FAQ in Platform Overview](https://github.com/ceskasporitelna/anemone#faq).

Arduino YÚN is able to **very often corrupt its memory and completely freeze**. *The Anemone platform is prepared to this* and in this case you can save the situation by performing the following:

1. Try to SSH to your Tentacle, if that is still possible, run there the Tentacle initialization script (`tentacle.sh`) again (if you do not have it, feel free to download it again from Anemone Cloud). The `tentacle.sh` is designed to be [idempotent](https://en.wikipedia.org/wiki/Idempotence) *(which simply means that it is OK to run it multiple times)*. `tentacle.sh` will initialize the Tentacle once again, and once again will install the *Initial Sketch*. But after 60s in its update period the *Initial Sketch* will automatically detect that some Anemone App is already installed on the Tentacle and will automatically perform the OTA to it. And because the Anemone App state *(= its variables)* is always stored in Anemone Cloud, your app will be back up with all its data. This should solve you issue.
2. If the hints from step 1. did not help *(probably because the Tentacle/Arduino YÚN is no longer responding to anything, including SSH)*, try to turn the Tentacle off and on (by cutting power to it - do not rely on the onboard reset buttons). When you plug it to power again, wait till the Arduino YÚN completes its booting - it will turn on the **white LED** on its surface - **it takes around 5 mins**. Now your Tentacle might resume its normal operations (that means that your Anemone App should boot up). If not, try if at least the SSH is working and follow instructions from step 1.
3. If even hints from step 2. were not helpful, your Arduino YÚN went completely stuck *(this happened multiple times to us durring the development of the platform ;))*. In this case nothing else than a **YÚN linux image reset** will help you. Follow instructions on the [official tutorial how to reset Arduino YÚN linux image](https://www.arduino.cc/en/Tutorial/YunSysupgrade). That usually helps. When done, follow with instructions from the step 1.

## Step 7 - *(Optional)* Install the "Juicy Day" example Anemone App on Tentacle

When your Tentacle is up and ready, you should see the following image on your Tentacle display:

<img alt="Anemone Tentacle UI - Ready for app installation" src="https://github.com/ceskasporitelna/anemone/raw/master/documentation/images/app_ready_for_installation.png">

Now you can open the *Anemone Cloud Administration* and from the list of apps select one app and install it to your Tentacle.

After installing the app, you should be able to access the app's *User Interface* in the *Anemone Mobile Client* iOS or Android app on your smartphone.

After 60s your Tentacle should initiate the *OTA update* and install the desired app.

<img alt="Anemone Tentacle UI - Juicy Day Currency Converter" src="https://github.com/ceskasporitelna/anemone/raw/master/documentation/images/app_converter.png">

> When performing the OTA update, Tentacle will turn off its display. **This is normal**. The OTA update will take some time to the slow Arduino YÚN. So if after 10s your Tentacle will still "look like unresponsive", don't panic and let it finish the OTA update. **It can take up to 5 minutes**. In case of issues, refer the [FAQ](https://github.com/ceskasporitelna/anemone#faq).

After another 60s at the latest Tentacle should synchronize app variables with the Cloud.

And now you are done ;).

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

*LEGO® is a trademark of the LEGO Group of companies which does not sponsor, authorize or endorse this site ([trademark guidelines](http://www.lego.com/en-us/legal/legal-notice/fair-play)).*