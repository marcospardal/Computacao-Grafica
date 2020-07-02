# Computação Gráfica
Repositório para apresentar os resultados das atividades práticas da disciplina de Introdução à Computação Gráfica, do período suplementar 2019.4 da UFPB.
Equipe: Marcos Davi Nascimento, matrícula: 20180025335 e Tiago Tito Gomes Amorim, matrícula: 20180164900

# Atividade 1
# Definição da atividade
O trabalho consiste na implementação de três funções: PutPixel, DrawLine, DrawTriangle. Juntas, são capazes de desenhar um triângulo usando o OpenGL.

# Estratégias utilizadas
## Dados
Foram utilizados dois structs. O primeiro, representa um pixel na tela e é formado por dois inteiros (X,Y) e quatro floats para as quatro bandas de cor(R,G,B,A). O segundo struct representa um triângulo, sendo composto de três pixels, para representar os vertices.

## Funções

### PutPixel
A função PutPixel recebe como parâmetro um Pixel, e com base em suas coordenadas (x,y) e a equação x*4 + y*w*4 encontra o deslocamento necessário para encontrar aquele pixel na memória.

![PutPixel](https://user-images.githubusercontent.com/49342589/85810047-2ed14000-b730-11ea-9574-0337f31bfb61.png)


### DrawLine
A função DrawLine é baseada no algoritmo de Bresenham, com alguns ajustes de modo que funcione para os 8 octantes. 
Primeiro verificamos se dy > dx, pois nestes casos, é preciso trocar o eixo x pelo eixo y nas equações do algoritmo de Bresenham. A lógica do algoritmo permanece a mesma, mas nestes casos, a decisão que precisa ser tomada é entre os pontos norte e nordeste. Com apenas este ajuste, já é possível traçar retas em dois octantes. 
Para generalizar para os outros 3 quadrantes, precisamos verificar se dx < 0 e/ou dy < 0. Sempre que a variação for negativa, é decrementada a respectiva variável, ao invés de somar como é feito convencionalmente.
Em resumo, as duas alterações relevantes ao algoritmo de bresenham são:

#### Verificação e inversão dos eixos x e y:
```
if(abs(dy) > abs(dx)){
        d = 2 * abs(dx) - abs(dy);
        incr_e = 2 * abs(dx);
        incre_ne = 2 * (abs(dx) - abs(dy));
    }else{
        d = 2 * abs(dy) - abs(dx);
        incr_e = 2 * abs(dy);
        incre_ne = 2 * (abs(dy) - abs(dx));
    }
 ```
 #### Verificação do sentido em que deve ir a reta:
 ```
  if(dx > 0)
    toPut.x++;
  else
    toPut.x--;

 ``` 
 
![DrawLine](https://user-images.githubusercontent.com/49342589/85810014-18c37f80-b730-11ea-9c67-d45604680fff.png)
 
 ### DrawTriangle
 A função DrawTriangle, recebe um struct do tipo triangle, e com acesso aos seus aos seus vertices, utiliza a função DrawLine para desenhar o triangulo na tela.

![DrawTriangle](https://user-images.githubusercontent.com/49342589/85810077-414b7980-b730-11ea-8069-40dc55efd2c9.png)
 
 ### Interpolação linear das cores
A interpolação linear das cores pode ser encontrada por meio da diferença de cor dos pontos dividido pela distância entre eles. Isto precisa ser feito para cada uma das bandas, RGBA. 

```
float Rcor, Gcor, Bcor;
float distance = sqrt(pow(dx,2.0) + pow(dy,2.0));

Rcor = (b.R - toPut.R) / distance;
Gcor = (b.G - toPut.G) / distance;
Bcor = (b.B - toPut.B) / distance;
```

# Extra
De forma adicional, foram realizadas tentativas de rotação do triângulo para fazer uma animação, porém, não terminamos a tempo, mas foi possível gerar alguns resultados interessantes. Fizemos também, uma função para desenhar circulos (não obteve resultados satisfatórios), uma função que desenha retas das arestas de um triângulo, até um de seus pontos, conseguindo assim o efeito de um triângulo preenchido e com cores que variam. 

![Triangulo_colorido](https://user-images.githubusercontent.com/49342589/85810093-4d373b80-b730-11ea-8bb3-c21dc72ad273.png)

![triangulo_circulo](https://user-images.githubusercontent.com/49342589/85810099-56280d00-b730-11ea-9825-621f0e659c6f.png)

# Dificuldades
Dentro das maiores dificuldades encontradas, podemos citar como destaque a matemática envolvida na implementação da simetria de um octante para os outros sete.

# Atividade 2
# Definição
O trabalho 2 consistia apenas na execução de um programa, que faz uso de shaders para desenhar um triângulo colorido na tela. O intuito do trabalho é verificar se a instalação do modern OpenGL foi feita da maneira correta.

# Resultados
![simplescreenrecorder-2020-07-02_10 29 25](https://user-images.githubusercontent.com/49342589/86403384-fbd50200-bc83-11ea-87a4-a796ab32e723.gif)

![link para o vídeo no youtube](https://youtu.be/z2vvUuqjJzA)

# Dificuldades
De início, o programa apresentou um triângulo em branco, pois ocorreu um erro ao carregar os shaders, isso foi facilmente corrigido digitando o seguinte comando no terminal "export MESA_GL_VERSION_OVERRIDE=3.3"
