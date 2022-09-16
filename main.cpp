#include "mbed.h"

//static BufferedSerial serial_port(USBTX, USBRX);
static BufferedSerial serial_port(PA_2, PA_3);
//static BufferedSerial serial_port(PA_9, PA_10); //PA_10=D2=UART1_RX  PA_9=D8=UART1_TX "Uso bluetooth"

AnalogIn pinMedido(PA_0); //PA_0=A0


float datoMedido;
char mensaje[40]={0};
int dato_Entero;
int dato_decimal;

//funcion decimal entero
void Decimal_Entero(float decimal){
    dato_Entero=int(decimal);
    dato_decimal=(decimal-int(decimal))*1000;
}

// main() runs in its own thread in the OS
int main()
{
serial_port.write("Hola.!  Arranque del programa.\n\r",32);

    while (true) {
        datoMedido=(pinMedido.read()*3.3);
        Decimal_Entero(datoMedido);
        sprintf(mensaje,"%d.%d\n\r",dato_Entero,dato_decimal);
        serial_port.write(mensaje,sizeof(mensaje));
       ThisThread::sleep_for(500ms);
    }
}

