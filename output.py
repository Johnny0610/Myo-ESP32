import subprocess
import time
from io import open

print("Iniciando programa...")

aux=""
n=0
mode=""
pose=""

# Ejecutar el archivo .exe (hello-myo.exe en este caso)
process = subprocess.Popen("hello-myo.exe", stdout=subprocess.PIPE, universal_newlines=True)
print("Se ejecutó el archivo .exe")

# Leer y mostrar la salida
#while process.poll() is None:
while n<35:
    output = process.stdout.readline().rstrip()
    if output != aux:
        archivo = open("data_temp.txt", "w")
        archivo.write(output)
        print(output)
        aux=output
        archivo.close()

        mode=output[61:69].replace(" ","")
        pose=output[74:88].replace(" ","")
        print(mode)
        print(pose)
        n+=1

print("Salimos del bucle")

# Terminar la ejecución del proceso
process.terminate()
print("Se cerró el .exe")


print("Se cerró el archivo .txt")

exit_code = process.returncode
print("El programa ha finalizado con código de salida:", exit_code)