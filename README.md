# Projeto: Interrupções BitDogLab

## 📌 Descrição
Este projeto explora o uso de interrupções no microcontrolador RP2040 utilizando a placa BitDogLab. Ele implementa controle de LEDs RGB, botões com debounce via software e uma matriz de LEDs WS2812 para exibir números de 0 a 9.

## 👥 Aluno

- **Breno Tainan Aguiar**

## 📺 Demonstração
🎥 Vídeo demonstrando o funcionamento do projeto: [Youtube](https://youtu.be/vAZm6PcMYNk)
- Explicação breve das funcionalidades.
- Demonstração da matriz de LEDs exibindo números de 0 a 9.
- Comprovação do funcionamento das interrupções nos botões.

## 🎯 Objetivos
- ✅ Compreender e aplicar interrupções em microcontroladores.
- ✅ Implementar debounce via software para botões.
- ✅ Controlar LEDs RGB e WS2812 para exibir números.
- ✅ Utilizar resistores pull-up internos para botões.
- ✅ Criar um sistema funcional combinando hardware e software.

## 🛠️ Componentes Utilizados
- 🖥️ **Microcontrolador RP2040 (Placa BitDogLab)**
- 🔴 **LED RGB (Pinos: GPIO 11, 12 e 13)**
- 🔘 **Botão A (GPIO 5) e Botão B (GPIO 6)**
- 🔳 **Matriz 5x5 de LEDs WS2812 (GPIO 7)**

## ⚙️ Funcionalidades Implementadas
1️⃣ **O LED vermelho do RGB pisca 5x por segundo.**
2️⃣ **O botão A incrementa o número exibido na matriz de LEDs.**
3️⃣ **O botão B decrementa o número exibido na matriz de LEDs.**
4️⃣ **Os LEDs WS2812 exibem números de 0 a 9 em formato digital.**

## 📂 Estrutura do Projeto
```
interrupcoes-bitdoglab/
├── build/                      # Diretório de compilação
├── includes/                   # Cabeçalhos das bibliotecas
│   ├── animacoes.h
│   ├── botao.h
│   ├── led-rgb.h
│   ├── matriz-led.h
├── src/                        # Implementações das funções
│   ├── animacoes.c
│   ├── botao.c
│   ├── led-rgb.c
│   ├── matriz-led.c
├── interrupcoes-bitdoglab.c     # Código principal
├── interrupcoes_bitdoglab.pio   # Código PIO para manipular matriz de leds
├── CMakeLists.txt               # Configuração do CMake
├── pico_sdk_import.cmake        # Importação do SDK do Raspberry Pi Pico
├── wokwi.toml                   # Configuração para simulação no Wokwi
└── README.md                    # Documentação do projeto
```

## 🔧 Configuração e Execução
### 🛠️ Configuração do Ambiente
1. Instale o **SDK do Raspberry Pi Pico** seguindo a [documentação oficial](https://datasheets.raspberrypi.com/pico/getting-started-with-pico.pdf).
2. Clone este repositório:
   ```sh
   git clone https://github.com/brenotainandev/interrupcoes-bitdoglab
   cd interrupcoes-bitdoglab
   ```
3. Configure o ambiente do CMake:
   ```sh
   mkdir build && cd build
   cmake ..
   make
   ```

### ▶️ Execução
1. Conecte a placa BitDogLab ao computador via USB.
2. Arraste o arquivo `interrupcoes-bitdoglab.uf2` gerado no diretório `build` para a unidade montada do Raspberry Pi Pico.


## 👨‍💻 Contribuição
Contribuições são bem-vindas! Siga os passos abaixo:
1. Faça um fork do repositório.
2. Crie um branch para sua funcionalidade (`git checkout -b minha-melhoria`).
3. Commit suas mudanças (`git commit -m 'Melhoria: Adicionando XYZ'`).
4. Envie para o branch principal (`git push origin minha-melhoria`).
5. Abra um **Pull Request**.

## 📜 Licença

Este projeto é de **uso educacional** e segue a licença MIT. Sinta-se à vontade para modificá-lo e contribuir!