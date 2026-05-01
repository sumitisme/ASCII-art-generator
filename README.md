# ASCII-art-generator

## Prerequisites for the device:

<p>The followings are expected in the system: </p><br>
* An instance of MinGW installed in the system (the msys64 installation recommended)

## To run the project (these steps are to run it in powershell):

* Make a build folder and cd into it

```shell
mkdir build
cd build
```

* Make the build files

```shell
cmake -G "MinGW Makefiles" ..
```

* Run the generated makefile

```shell
mingw32-make
```

* Run the executable

```shell
.\ASCII-generator.exe '..\image\outra mãe- coraline.jpg'
```