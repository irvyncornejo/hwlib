# Librería para control de shield kaanbal o chimalli
## Kaanbal
* Shield para Arduino nano
* C++

### Comprimir para importar en IDE
* Comprimir archivo en power shell, para después añadir desde el IDE de arduino.
    ```
    Compress-Archive .\kaanbal-lib\*.* -DestinationPath .\kaanbal.zip -F
    ```
### Copiar a la carpeta de libraries
```
$user="irvyn"
Copy-Item -Path "C:\Users\$user\Documents\ic\hwlib\Kaanbal" -Destination "C:\Users\$user\Documents\Arduino\libraries" -Recurse -Force
```

## Chimalli
* Shield para Raspberri pi
* Python

![kaanbal-chimalli](https://drive.google.com/uc?export=view&id=15EJnb_c1G7KnUYNzaDpBNI2bReofG2Za)