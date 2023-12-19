from smbus import SMBus                                         #Biblioteca smbus para I2C
from time import sleep

addr = 0x42                                                     #Endereço I2C (0x42)

bus = SMBus(1)                                                  #cria o objeto SMBus associado ao canal 1 de I2C da Rasp

while True:
    data = bus.read_i2c_block_data(addr, 0, 2)    
    Tensao = 256*data[0]+data[1]                                #Como no programa arduino o highByte é passado primeiro, data[0] é o highByte enquanto data[1] é o low
    Tensao = round(Tensao*(5/1023), 3)                          #Conversão para valor de 0 a 5V
    print("Valor analógico lido:"+str(Tensao))                  #Printa o valor lido em Volts
    sleep(1)                                                    #delay para não haver erro de Remote I/O