# EmbarcaTech_atividade_PWM

## Descrição

Este projeto tem como objetivo explorar e implementar a comunicação serial utilizando a placa de desenvolvimento **BitDogLab** com o microcontrolador **RP2040**. Durante o desenvolvimento, foi empregado o protocolo **PWM** para controle de um **servomotor** e um **LED RGB**, além da simulação da solução no ambiente **Wokwi**.

## Componentes Utilizados

- **Microcontrolador Raspberry Pi Pico W**
- **Servomotor (micro servo padrão)** – GPIO 22
- **LED RGB** – GPIO 12

## Funcionalidades Implementadas

1. **Configuração do PWM**
   - Frequência ajustada para **50Hz** (Período de 20ms) na GPIO 22.
   - Cálculo e configuração dos ciclos de trabalho para movimentação do servomotor.

2. **Controle de Posições do Servomotor**
   - **0 graus:** Pulso de 500µs
   - **90 graus:** Pulso de 1470µs
   - **180 graus:** Pulso de 2399µs
   
3. **Movimentação Suave do Servomotor**
   - Variação do pulso em incrementos de **±5µs** com atraso de **10ms**, garantindo deslocamento contínuo e suave entre **0° e 180°**.

4. **Controle do LED RGB via PWM**
   - Nível de brilho ajustado conforme o ciclo de trabalho do servomotor.

## Requisitos

- **Uso do PWM:** O controle do servomotor e do LED RGB foi feito via PWM.
- **Desenvolvimento em C:** Código implementado utilizando **Pico SDK**.
- **Ambiente de Desenvolvimento:**
  - **VS Code** integrado ao **simulador Wokwi**.

## Instruções de Uso

1. Clone o repositório do projeto:
   https://github.com/FilipeVBF/EmbarcaTech_atividade_PWM.git
2. Importe a pasta do projeto para o ambiente de desenvolvimento do **Pico SDK**.
3. Conecte o hardware conforme a configuração sugerida.
4. Compile e carregue o código no **Raspberry Pi Pico W**.
5. Para execução na simulação do **Wokwi**, abra o arquivo diagram.json e inicie a simulação.
6. Observe a movimentação do servomotor e a variação do brilho do LED RGB.

## Vídeo da Solução
Segue abaixo o link do vídeo da demonstração do projeto:
[Ver vídeo](https://drive.google.com/file/d/1a79V0lfpZY5stYrGUfLc_5bbc5y0wgtd/view?usp=sharing).
