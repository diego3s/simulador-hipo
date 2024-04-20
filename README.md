<h1 align="Center">Simulador HIPO</h1>

<p align="center">
    <a href="#descricao">Descrição do projeto</a> •
    <a href="#pre-requisitos">Pré-requisitos</a> •
    <a href="#instalacao">Instalação</a> •
    <a href="#como-usar">Como usar</a> •
    <a href="#autores">Autores</a>
</p>  

## ⌨️ Descrição do projeto

![Funcionamento](https://github.com/diego3s/simulador-hipo/assets/51541419/35aa3718-4765-40ea-a993-7b04c9d59ff8)

Simulador para o computador HIPO construído como trabalho para a disciplina de Paradigmas de Programação, utilizando os conceitos de orientação a objetos no C++, a bibliteca SFML e o compilador GCC no Linux.

O simulador recebe como entrada um arquivo-texto contendo o programa para o HIPO e mostra a execução passo a passo.

>[!NOTE]
>Consulte a especificação do computador HIPO em: https://www.ime.usp.br/~jstern/miscellanea/MaterialDidatico/hipo.htm

## 📋 Pré-requisitos

O simulador foi desenvolvido utilizando o Linux, portanto foi testado somente nesse sistema operacional. Para executar o simulador é necessário possuir instalado no computador:

**GCC:**
```bash
sudo apt-get install gcc 
```

**CMake:**
> [Instalar o CMake](https://cmake.org/download/)

**SFML:**
> [Instalar a SFML](https://www.sfml-dev.org/tutorials/2.6/start-linux.php)

## ⚒ Instalação

```bash
# Clone este repositório
git clone https://github.com/diego3s/simulador-hipo.git

# Acesse a pasta do projeto no seu terminal
cd simulador-hipo

# Crie uma pasta build e acesse-a
mkdir build && cd build

# Compile o código
cmake ..
make

# Execute o programa
./simulador-hipo
```

## 💡 Como usar

Após executar o programa, informe o caminho para o arquivo .hipo desejado, depois execute o passo a passo do programa(F5), os inputs e outputs são mostrados no terminal. 

> Acesse o diretório ./exemplos para códigos de teste.

## 🖋 Autores
- Bruno Henrique
- Diego Samuel