#define ENTERO 0x304FFFF  // 10 segundos a 80 MHz
#define FLOTANTE 0xF52FF


void TestFlotantes(){
   // Prueba con flotantes
    long t_inicio = millis();
    volatile float sum_float = 0.0;
    // Bucle que ejecut a sumas de flotantes
    for (long i = 0; i < FLOTANTE; i++) {
        sum_float += 1.0 / (i + 1);   //Suma progresiva de flotantes
    }


    Serial.print("Tiempo con Flotantes: ");
    Serial.print(millis() - t_inicio);
    Serial.println(" [ms]");
    Serial.println();
}


void TestEnteros(){
    // Prueba con enteros
    long t_inicio = millis();
    volatile long contador = 0;
    // Bucle que ejecut a sumas de enteros
    while (contador <= ENTERO) {
        contador += 1;  // Suma continua
    }
   
    Serial.print("Tiempo con Enteros: ");
    Serial.print(millis() - t_inicio);
    Serial.println(" [ms]");
}


void FrequencyTest(int Freq){
    setCpuFrequencyMhz(Freq);
    Serial.print("Frecuencia de la CPU: ");
    Serial.print(getCpuFrequencyMhz());
    Serial.println(" MHz");


    TestEnteros();
    TestFlotantes();
    Serial.println("-------------------");
}


void setup() {
    Serial.begin(115200);  // Iniciar la comunicación serial
    Serial.println("Iniciando ejecución...");


    FrequencyTest(80);    // Testeo de ESP32 a 80/160/240 [MHz]
    FrequencyTest(160);
    FrequencyTest(240);


    Serial.println("Ejecución terminada.");
}


void loop(){
}
