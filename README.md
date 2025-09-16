# EdgeComputingCP4
# CP4 - PoC Smart Lamp (ESP32 + DHT11 + LDR → ThingSpeak)

## Autores
- Nuno Coutinho Henrique RM562438
- Yasmin Amorim Affonso RM563645

Professor: Paulo Marcotti  
Data: 04/09/2025  

---

## Descrição
Este projeto implementa um protótipo de monitoramento para vinherias (*PoC Smart Lamp*) utilizando:
- ESP32
- Sensor DHT22 (temperatura e umidade)
- Sensor LDR (luminosidade, %)

Os dados são enviados periodicamente (≥ 15s) para a **plataforma ThingSpeak**, que armazena e exibe gráficos em tempo real.

---

## Como rodar no Wokwi
1. Acesse o link da simulação:  
   👉 [Simulação Wokwi](https://wokwi.com/projects/442214424556517377)

2. O ESP32 conecta ao Wi-Fi simulado `Wokwi-GUEST` (sem senha).  
3. Dados de temperatura, umidade e luminosidade são enviados para o canal configurado no ThingSpeak.  
4. No Serial Monitor é possível acompanhar leituras e confirmações HTTP.

---

## Evidências entregues
- Código fonte no GitHub: este repositório  
- [Simulação Wokwi](https://wokwi.com/projects/442214424556517377)  
- [Vídeo (YouTube)](INSERIR_LINK_AQUI)  
