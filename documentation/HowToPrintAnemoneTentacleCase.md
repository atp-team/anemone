# How to 3D print Anemone Tentacle Case

In this tutorial, we will guide you throught the 3D printing the *Anemone Tentacle case*.

> Anemone Tentacle case is in fact the very **first 3D printed Arduino YÚN case which is using the Arduino TFT Display** in the world! An it can be used even outside of the Anemone Platform. Feel free to use it even for your other projects ;).

TODO image 3D model wired

TODO image 3D model shaded

TODO image 3D model rendered

TODO final Anemone Tentacle printed and running

> For the *How to build* Anemone Tentacle refer to a separate page of our tutorial, see [How to build Anemone Tentacle](https://github.com/ceskasporitelna/anemone/blob/master/documentation/HowToBuildAnemoneTentacle.md).

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
* The Top *(LEGO® compatible)* cover
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

LEGO® is a trademark of the LEGO Group of companies which does not sponsor, authorize or endorse this site ([trademark guidelines](http://www.lego.com/en-us/legal/legal-notice/fair-play)).