
# Scribblenauts 3D object summoning

How to use:

Type the 3d model you want to spawn
Click on Accept 
![image](https://github.com/AndresPiola/ScribbleAINauts/assets/67182081/60ae4981-105e-4e9c-afd6-f1dd21d94876)
![image](https://github.com/AndresPiola/ScribbleAINauts/assets/67182081/a4d2e7c2-2c82-4da5-959d-ff68e762fefc)

Setting Up:
Models are downloaded from poly pizza. For this you need a valid api key.
Instructions of how to generate the Api Key
https://poly.pizza/docs/api

The request is called from an Actor Component called HttpConnect
![image](https://github.com/AndresPiola/ScribbleAINauts/assets/67182081/85477680-f34f-43f1-8c3e-3c6e4191ec74)
Here you set your api key

Importing models:
Call the function with keywords
![image](https://github.com/AndresPiola/ScribbleAINauts/assets/67182081/66aa43aa-70b8-4e00-9cae-be3e47103a26)
This is an Async event. That means that when the process is completed you get an array with all models that matchs the query keywords
![image](https://github.com/AndresPiola/ScribbleAINauts/assets/67182081/feab0137-119b-4400-a83b-7e99f4a1a990)

The result is a glb file that is imported using gltf plugin

![image](https://github.com/AndresPiola/ScribbleAINauts/assets/67182081/d1e1cf73-dd72-474f-8556-6bc9dceab567)

https://github.com/rdeioris/glTFRuntime



