# Anemone

> Look at you hacker, in order to use me, you must understand first.
> - anemone

## Introducing the Platform

Anemone is an open platform which allows you to experiment with *Internet of Things*. Anemone allows you to easily **build open hardware device** and to **create a simple apps** which will run *both in cloud and on mobile devices*.

First take a look at our website [http://www.anemone.cloud](http://www.anemone.cloud).

Then continue reading.

## Platform architecture

Anemone has three main components:

* Mobile Client
* Tentacle
* Cloud

**Mobile Client** is iOS and Android application which allows you to manage *Tentacles* and control *Anemone Apps*. You can download it for free from Apple AppStore and Google Play Store. Both links are on our website [http://www.anemone.cloud](http://www.anemone.cloud).

TODO images

**Tentacle** is open hardware device based on Arduino YÚN which is the *Internet of Things* part the our platform. You can either *connect as a guest* to a Tentacle of your friend, or you can *build your own* (which will recognize you as its master).

TODO images

**Cloud** is the final component of the platform which connects the Tentacles to the Mobile Client. But that is not all. The Anemone Cloud can connect both the Mobile Client and Tentacles to other API service in the internet using **Connectors**.

TODO architecture image

The *Cloud*, *Mobile Client* and *Tentacle* together form a platform where **Anemone Apps** can run.

And *Anemone Apps* are here for you *to use them*, *to develop them* and mainly **to have some fun with them**.

## How it works? 

> Main goal of Anemone Platform is to provide a place where *Anemone Apps* can live.

TODO

## This looks Awesome! How can I start?

You can use the Anemone platform either as a **User** or as a **Developer**.

In order to start *as a User*, all you need to do is:

1. Download the **Mobile Client app for iOS or Android** (you can find links to apps on our website [http://www.anemone.cloud](http://www.anemone.cloud))
2. Find some **Tentacle** which you would like to control. In order to control a Tentacle, you need to either *own it* (which means to [build it](TODO) first), or be invited to it *as a guest*.
3. Take a full control of the Tentacle. You can **control the running app** as both guest and owner. Or **switch the running app** for another one or **trigger Tentacle share mode** as owner.  Both can be done from the Mobile Client or Cloud administration.

When starting *as a Developer* do the following:

TODO

## Who Is Behind This?

Anemone platform is a result of cooperation between [Honza Sechovec](https://twitter.com/jansechovec) and [Juicymo](http://www.juicymo.cz).

It could never be created without support from [Česká Spořitelna](TODO) and their [WebAPI](TODO) Team (TODO je toto OK, Honzo?)

Anemone has been created with love in Prague.

In case of any question or issue, feel free to add a GitHub Issue in this repository.

The Anemone Cloud service is operated by [WebAPI Team](TODO) of [Česká Spořitelna](TODO).

### Special thanks

For their great effort we owe a BIG thank to the following people and entities from the joint project development team (everybody did *a lot more* then what was expected from him):

* *Pedro Pinto da Silva* for the outstanding graphical design of the entire platform including website, mobile app, Arduino app UI and infographics. This platform design has a story.
* *Martin Svoboda* for the development of Anemone Cloud Ruby on Rails application, manifest and interface JSON parsers and database.
* *Šimon Kautský* for the development of Anemone Mobile Client app both for iOS and Android in Unity3D and for solving all these ugly platform specific bugs.
* *Filip Bursík* for the development of Arduino part of Anemone platform in C and for all those dreamless nights when the program did not fit the small Arduino YÚN memory.
* *Michal Mlejnek* for the huge amount of Anemone Tentacle 3D case model iterations in Blender - including the final one which you can print and enjoy.
* *Jana Moudrá* for coding the Anemone platform presentational website (the one at [http://www.anemone.cloud](http://www.anemone.cloud)). Fully responsive with all the cute JS features.
* *Honza Sechovec* for the vision, guidance and mainly for the patience. The development of the platform took a lot longer than expected, but the result is worth it.
* *Tomáš Jukin* for the platform architecture and the fact that all the stuff fits well together. And for the ugly electronics stuff, the documentation, slicing, soldering and 3D printing.
* *Kanárek* (which is a [Prusa3D i3 MK2 3D printer](http://www.prusa3d.cz/#i3-printer)) for printing every single iteration of the Anemone Tentacle 3D case model and still work.

## How can I contribute?

1. Join the platform! Either as a User or Developer, you can join the Anemone platform and explore the world of IoT in a fun way. See [http://www.anemone.cloud](http://www.anemone.cloud).
2. Spread the word! I you know somebody who might be interested in our platform invite him ale show him your Tentacle.
3. Make your own apps based on [manual](TODO).
4. Make new connectors and submit them as pull requests to this repository.
5. Interested in serious development? Wanna extend the platform itself? Contact Honza at [TODO EMAIL?](TODO).

## I want more of it! - What to do next?

1. Check out our [website](http://www.anemone.cloud)
2. [Sign up](http://www.anemone.cloud/users/sign_up) for free and [download the Mobile Client](http://www.anemone.cloud)
3. Read the [How to build Anemone Tentacle](TODO) tutorial
4. Read the [How to make Anemone App](TODO) tutorial (or directly [How to define Anemone App Logic in manifest.json](TODO), [How to define Anemone App User Interface in interface.json](TODO) or [How to create Anemone App Sketch in Arduino IDE]())
5. Read the [How to make Anemone Connector](TODO) tutorial
6. You may be also interested in a [Anemone Apps Repository](TODO), [List of available Anemone Connectors](TODO) and [Anemone Libraries documentation](TODO)
7. Explore the "Juicy Day" [example Anemone App on our GitHub](TODO).

## FAQ

### How can I connect to a Tentacle as a Guest?

> You need to access the Tentacle physically and press the *cloud button* (located below the left bottom corner of the screen). Or you can convince the Tentacle owner to press the *key button* in his Mobile Client app on his Tentacle info page.

> This will initiate a **share mode** of the Tentacle. When in this mode, Tentacle will show a four digit guest code on its screen - eg. 1234.

> When you physically access a Tentacle in share mode, you can type its guest code to your Mobile Client app (after pressing the *Add Tentacle* button on the dashboard).

> The Tentacle will now appear in your Mobile Client under the *Guest Boxes* label. You can now control the *Anemone App* which is running on it.

### How can I build a Tentacle?

> Just follow our [manual](TODO). It includes a *part list* and even a *model of cute case* which can be 3D printed! All the difficult stuff is done, what remains are just the fun parts ;).

## Terms and License

This software is licensed under [MIT license](TODO).




