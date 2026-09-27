# Sistema Embarcado para Sinalização de Parada de Ônibus

Projeto acadêmico de um sistema embarcado destinado à simulação de um sistema de solicitação de parada de ônibus.

## Descrição

O sistema foi desenvolvido e simulado no ambiente Wokwi, com autorização do professor, utilizando uma placa STM32L031K6T6.

O funcionamento consiste em registrar uma solicitação de parada realizada por meio de um botão. Quando o botão é pressionado, o sistema:

- Acende o LED vermelho;
- Apaga o LED azul;
- Ativa o buzzer durante 3 segundos;
- Mantém a solicitação ativa após o desligamento do buzzer.

A solicitação permanece ativa até que o sensor que representa a abertura da porta seja acionado. Nesse momento, o sistema encerra a solicitação e retorna ao estado inicial.

## Componentes

- STM32L031K6T6
- LED vermelho
- LED azul
- Buzzer
- Botão de solicitação de parada
- Botão representando o sensor da porta
- Resistores

## Mapeamento dos pinos

| Componente | Pino | Função |
|---|---|---|
| LED vermelho | D2 | Solicitação de parada ativa |
| LED azul | D3 | Sistema aguardando solicitação |
| Buzzer | D4 | Alerta sonoro |
| Porta | D5 | Sensor de abertura da porta |
| Botão de parada | D6 | Solicitação do passageiro |

## Funcionamento

### Estado inicial

- LED azul: ligado
- LED vermelho: desligado
- Buzzer: desligado

### Solicitação de parada

Quando o botão é pressionado:

- LED azul é desligado;
- LED vermelho é ligado;
- Buzzer é ativado por 3 segundos;
- A solicitação permanece registrada.

### Atendimento da solicitação

Quando a porta é aberta:

- LED vermelho é desligado;
- LED azul é ligado;
- Buzzer é desligado;
- A solicitação é encerrada.

## Tecnologias utilizadas

- C/C++
- STM32L031K6T6
- Wokwi
- Programação de sistemas embarcados

## Arquivo principal

O código do projeto está disponível no arquivo:

`parada_onibus.ino`

## Observação

A proposta original da atividade mencionava a utilização de um CPLD EPM3064 e VHDL. A implementação prática deste projeto foi realizada utilizando o STM32L031K6T6 e linguagem C/C++, no ambiente Wokwi, conforme autorizado pelo professor.
