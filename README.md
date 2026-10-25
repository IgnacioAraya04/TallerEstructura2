Ignacio Araya Munizaga / 21.824.045-3 / IgnacioAraya04 / ITI

El archivo utilizado para obtener los pacientes se llama "pacientes.txt", se puede modificar para agregar más pacientes.

Para el arbol de decisión se decidio usar el siguiente criterio:

Se inicia con preguntado por pediatria y neurologia, ya que determinamos que eran los servicios mas rápidos de determinar, seguido por traumatologia y cirugia, que van relacionadas entre si ya que determinamos que para que se tenga que realizar cirugia, debe haber una razón fisica (trauma). Si ninguno de los criterios anteriores se cumple se contirnua revisando al paciente, si su presión arterial es mayor a 180 (umbral en el que se requiere intervencion medica según google) se deberá mandar al paciente hacia cardiologia. Siguiendo con la linea se revisa el dolor o la temperatura del paciente, si el dolor es igual o mayor a 7 (en la escala del 1 al 10) determine que deberia enviarse a urgencias, usualmente pondria de 8 para arriba, pero es mejor mandar a urgencias a alguien que no lo necesite a que no mandarlo y que realmente lo necesite, a su vez establecí el limite de temperatura en 38.5 ya que al rededor de esa temperatura es cuando puede llegar a ser critica para el cuerpo humano, en caso de no cumplir ninguno de los criterio anteriores, será enviado a medicina general, pero si sus dias de hospitalización son mayores a 1, entonces sera hospitalizado en su lugar.

Instrucciones de compilación:
utilizar el siguinte comando en la terminal del codespace para compilar:
g++ -std=c++17 -IHeaders Body/*.cpp -o hospital

Luego el siguiente codigo para iniciar el programa:
./hospital