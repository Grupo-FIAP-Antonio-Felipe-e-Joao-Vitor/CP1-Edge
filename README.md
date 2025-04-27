Monitor de Luminosidade com Arduino
Descrição do Projeto
Este projeto utiliza um Arduino Uno, um sensor de luminosidade, uma tela LCD (16x2), LEDs e um buzzer para monitorar a quantidade de luz em um ambiente.
A luminosidade captada é convertida em porcentagem utilizando a função map() do Arduino, e o valor é exibido em tempo real na tela LCD.

O sistema opera em três estados de alerta:

Estado OK:

Luz ambiente adequada.

LED verde aceso.

Sem som no buzzer.

Estado de Alerta:

Luz ambiente em nível de atenção.

LED amarelo aceso.

Buzzer emite bips intermitentes (Bip-Bip-Bip) até o retorno ao estado OK.

Estado Crítico:

Luz ambiente em nível crítico.

LED vermelho aceso.

Buzzer emite um som contínuo (Biiiiiiiip) até o retorno ao estado OK.

Componentes Utilizados
1x Arduino Uno

1x Breadboard

1x Sensor de Iluminação (ex: LDR com resistor de pull-down)

1x Tela LCD 16x2 (com ou sem módulo I2C)

1x LED verde

1x LED amarelo

1x LED vermelho

1x Buzzer (ativo ou passivo)

Resistores diversos (para LEDs e sensor)

Fios jumper

Dependências
Para compilar e rodar o projeto no Arduino IDE, você precisa:

Arduino IDE (versão 1.8.19 ou superior, ou Arduino Web Editor)

Biblioteca LiquidCrystal (já vem embutida na IDE padrão)
Se estiver usando módulo LCD com I2C, será necessário instalar a biblioteca:

LiquidCrystal_I2C

Como Reproduzir
Monte o circuito:

Conecte o sensor de luz a uma entrada analógica do Arduino (por exemplo, A0).

Conecte os LEDs (verde, amarelo e vermelho) a saídas digitais do Arduino com resistores.

Conecte o buzzer a uma saída digital do Arduino.

Conecte a tela LCD aos pinos digitais correspondentes (ou via I2C).

Faça o upload do código:

Abra o Arduino IDE.

Selecione a placa correta (Arduino Uno) e a porta serial.

Copie e cole o código-fonte no editor.

Compile e envie o código para o Arduino.

Teste o sistema:

Varie a iluminação sobre o sensor e observe:

A porcentagem de luz sendo exibida no LCD.

Mudanças nos LEDs e sons conforme os níveis de luminosidade.

