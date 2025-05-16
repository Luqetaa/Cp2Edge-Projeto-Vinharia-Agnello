# Sistema de Monitoramento Ambiental com Arduino
 
## 📌 Descrição do Projeto
 
Este projeto consiste no desenvolvimento de um sistema de monitoramento ambiental utilizando a plataforma Arduino. O sistema é capaz de medir e exibir, em tempo real, os níveis de temperatura, umidade e luminosidade de um ambiente. Além disso, fornece alertas visuais e sonoros quando os parâmetros monitorados estão fora dos limites ideais, visando aplicações como o controle de ambientes de armazenamento de vinhos.
 
## 🎯 Objetivo
 
Desenvolver uma solução de baixo custo e fácil implementação para monitorar condições ambientais críticas, garantindo a manutenção da qualidade de produtos sensíveis a variações de temperatura, umidade e luminosidade.
 
## 🛠️ Componentes Utilizados
 
* [Placa Arduino Uno R3]()
* [Sensor DHT22 de temperatura e umidade]()
* [Sensor LDR de luminosidade]()
* [Display LCD 16x2 com interface I2C]()
* [LEDs indicadores (verde, amarelo e vermelho)]()
* [Buzzer piezoelétrico]()
* Resistores de 10kΩ
* Protoboard e jumpers
 
## ⚙️ Funcionamento
 
1. **Leitura de Dados:** Os sensores capturam os valores de temperatura, umidade e luminosidade do ambiente.
2. **Processamento:** O Arduino processa os dados e determina se os valores estão dentro dos limites ideais.
3. **Exibição:** As informações são exibidas no display LCD.
4. **Alertas:**
 
   * **Visuais:** LEDs indicam o estado de cada parâmetro:
 
     * Verde: dentro dos limites ideais.
     * Amarelo: atenção.
     * Vermelho: fora dos limites aceitáveis.
   * **Sonoros:** O buzzer é acionado em situações críticas.
 
## 🔧 Instruções de Montagem
 
1. **Conexões:**
 
   * [Sensor DHT22](): VCC ao 5V do Arduino, GND ao GND, e DATA ao pino digital 2.
   * [Sensor LDR](): Conectado ao pino analógico A0 com resistor de 10kΩ.
   * [Display LCD 16x2 com interface I2C](): SDA ao pino A4, SCL ao pino A5.
   * LEDs: Conectados aos pinos digitais 3 (verde), 5 (amarelo) e 4 (vermelho) com resistores de 220Ω.
   * [Buzzer piezoelétrico](): Conectado ao pino digital 6.
 
2. **Código:**
 
   * Utilize a IDE do Arduino para carregar o código fornecido no projeto.
   * Certifique-se de instalar as bibliotecas necessárias: `DHT.h` e `LiquidCrystal_I2C.h`.
 
## 🧪 Testes Realizados
 
* **Simulações:** Utilização da plataforma Wokwi para simular diferentes condições ambientais e verificar o funcionamento do sistema.
* **Testes Práticos:** Montagem do circuito físico e exposição a diferentes ambientes para validar a precisão das leituras e a resposta dos alertas.
 
## 📈 Resultados Esperados
 
* Monitoramento contínuo das condições ambientais.
* Alertas imediatos em caso de desvios dos parâmetros ideais.
* Facilidade de interpretação dos dados através do display LCD e dos indicadores visuais e sonoros.
 
## 📚 Conclusão
 
O sistema desenvolvido demonstra ser uma solução eficiente e de baixo custo para o monitoramento de ambientes que exigem controle rigoroso de temperatura, umidade e luminosidade, como é o caso de adegas e locais de armazenamento de vinhos. Sua implementação pode contribuir significativamente para a manutenção da qualidade dos produtos armazenados.

## 🧑 Integrantes do Grupo

Manoah Leão 563713\
Matheus Rodrigues 561689\
Lucas Cavalcante 562857\
Caio Nascimento 561383\
