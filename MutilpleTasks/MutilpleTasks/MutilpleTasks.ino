
void coreTaskZero( void * pvParameters ){
  
    String taskMessage = "Task running on core ";
    taskMessage = taskMessage + xPortGetCoreID();
    //Serial.println(taskMessage);  //log para o serial monitor
  
    while(true){
      Serial.println(taskMessage);
      delay(5000);
    } 
}

void coreTaskOne( void * pvParameters ){
  
    String taskMessage = "Task running on core ";
    taskMessage = taskMessage + xPortGetCoreID();
    //Serial.println(taskMessage);  //log para o serial monitor
  
    while(true){
      Serial.println(taskMessage);
      delay(1000);
    } 
}

void setup() {
  Serial.begin(115200); 

xTaskCreatePinnedToCore(
                    coreTaskZero,   /* função que implementa a tarefa */
                    "coreTaskZero", /* nome da tarefa */
                    10000,      /* número de palavras a serem alocadas para uso com a pilha da tarefa */
                    NULL,       /* parâmetro de entrada para a tarefa (pode ser NULL) */
                    2,          /* prioridade da tarefa (0 a N) */
                    NULL,       /* referência para a tarefa (pode ser NULL) */
                    0);         /* Núcleo que executará a tarefa */
 
    delay(500); //tempo para a tarefa iniciar
 
   //cria uma tarefa que será executada na função coreTaskTwo, com prioridade 2 e execução no núcleo 0
   //coreTaskTwo: vigiar o botão para detectar quando pressioná-lo
   xTaskCreatePinnedToCore(
                    coreTaskOne,   /* função que implementa a tarefa */
                    "coreTaskOne", /* nome da tarefa */
                    10000,      /* número de palavras a serem alocadas para uso com a pilha da tarefa */
                    NULL,       /* parâmetro de entrada para a tarefa (pode ser NULL) */
                    2,          /* prioridade da tarefa (0 a N) */
                    NULL,       /* referência para a tarefa (pode ser NULL) */
                    1);         /* Núcleo que executará a tarefa */
}

void loop() {

}
