import subprocess
import time
import serial
from io import open

#variables
aux=""
aux1=""
aux2=""
pose=""
mode=""
info=""
cad=""
port="COM9" #En mi caso es el COM9, pero puede variar
baudrate=9600 #Esto depende del baudrate que se haya puesto en el código de Arduino

esp32 = serial.Serial(port,9600)
time.sleep(2)


# Ejecutar el archivo .exe (hello-myo.exe en este caso)
process = subprocess.Popen("hello-myo.exe", stdout=subprocess.PIPE, universal_newlines=True)
print("Se ejecutó el archivo .exe")
time.sleep(4)
# Leer y mostrar la salida
while process.poll() is None:

    output = process.stdout.readline().rstrip()
    if output != aux:
        archivo = open("data_temp.txt", "w")
        archivo.write(output)

        aux=output
        archivo.close()

        mode=output[61:69].replace(" ","")
        pose=output[74:88].replace(" ","")

        if mode!=aux2 or pose!=aux1:
            aux2=mode
            aux1=pose
            info = aux2 + "," + aux1
            print(info)
            esp32.write(info.encode("ascii"))

        
#esp32.close()
print("Salimos del bucle")

exit_code = process.returncode
print("El programa ha finalizado con código de salida:", exit_code)