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

link para o vídeo no youtube: https://youtu.be/z2vvUuqjJzA

# Dificuldades
De início, o programa apresentou um triângulo em branco, pois ocorreu um erro ao carregar os shaders, isso foi facilmente corrigido digitando o seguinte comando no terminal "export MESA_GL_VERSION_OVERRIDE=3.3"

# Atividade 3
# Definição 
O trabalho 3 consistia em aplicar transformações geométricas. Esta implementaçãp será feita com auxílio da biblioteca glm e sua execução ocorrerá nos shaders do OpenGL.

# Cena
![cena_original](https://user-images.githubusercontent.com/49342589/88868289-21ebb480-d1e6-11ea-86eb-70c1be2abbf0.png)


# Exercícios 
## 1 - Escala
Modificar a matriz Model com os fatores de escala em (x, y, z) = (1/3, 3/2, 1).

### Matriz Model
![Matriz_exerc_um](https://user-images.githubusercontent.com/49342589/88866689-d0d9c180-d1e1-11ea-9333-4ef69e4c4d46.png)

### Resultado
![exercicioUm](https://user-images.githubusercontent.com/49342589/88866622-9c660580-d1e1-11ea-9555-5a3e942b989c.png)

## 2 - Translação
Modificar a matriz Model de forma que ocorra translações em (x, y, z) = (1, 0, 0).

### Matriz Model
![Matriz_exerc_dois](https://user-images.githubusercontent.com/49342589/88866850-3b8afd00-d1e2-11ea-8563-efa0464f2fe9.png)

### Resultado
![exercicioDois](https://user-images.githubusercontent.com/49342589/88866894-58273500-d1e2-11ea-8cf1-bdfa9e559afd.png)

## 3 - Projeção Perspectiva
Modificar a matriz M-Projection de modo que o triângulo vermelho, que está na frente, fique mais distante do azul.

### M-Projection
![M-Projetcion_explicacao](https://user-images.githubusercontent.com/49342589/88867166-0a5efc80-d1e3-11ea-9ec1-d52166ec8417.png)
![Matriz_exerc_tres](https://user-images.githubusercontent.com/49342589/88867187-1c409f80-d1e3-11ea-80ea-ab279796beda.png)

### Resultado
![exercicioTres](https://user-images.githubusercontent.com/49342589/88867223-3ed2b880-d1e3-11ea-8160-6450eb383931.png)

## 4 - Posição da Câmera
Modificar a matriz M-view para movimentar a posição da câmera, mantendo as alterações feitas no exercício três. Alterações necessárias: Posicão da câmera = (-1/ 10, 1/10, 1/4), vetor Up da câmera = (0, 1, 0), alvo da câmera = (0, 0, 0). A nova matriz view será definida pela multiplicação da transposta de B vezes T.

### Alterações
![matrizes_exerc_quatro](https://user-images.githubusercontent.com/49342589/88868056-85291700-d1e5-11ea-9f77-a1d8f5e7f0a5.png)

### Resultado
![exercicioQuatro](https://user-images.githubusercontent.com/49342589/88868096-a427a900-d1e5-11ea-89d4-d406d0f67548.png)

## 5 - Transformações livres
Realizar modificações nas matrizes model, view e projection de forma que gerem uma cena diferente da anterior.

### Matrizes
![Matrizes_exerc_cinco](https://user-images.githubusercontent.com/49342589/88868226-f4067000-d1e5-11ea-8142-0c5bb9488118.png)

### Resultado
![exercicioCinco](https://user-images.githubusercontent.com/49342589/88868249-054f7c80-d1e6-11ea-8631-1ea10f023eaf.png)

# Atividade 4
## Definição
Familiarizar os alunos com os modelos de iluminação tradicionalemente utilizados na rasterização: ambiente, difuso e especular. Deverão ser implementados os três modelos utilizando vertex shader do OpenGL.

## Exercício 1
### Definição
O exercício 1 consistia em modificar o vertex shader para incluir o modelo difuso. Para isto precisamos calcular um novo valor de vetor normal N, e um novo vetor L apontando do vértice para a fonte de luz.

### Vetores Calculados
vec3 L = normalize ( I_p_pos - ( model_mat * vec4 ( obj_spc_vertex_pos , 1.0) ) .←- xyz ) ; 

vec3 N = normalize ( mat3 ( transpose ( inverse ( model_mat ) ) ) * obj_spc_N ) ;

### Modelo difuso:
I = Ia*κa + Ip*κd *(N*L)

### Parâmetros
Ia = (0.2,0.2,0.2)

ka = (0,0,1)

Posição da fonte de luz = (-2,2,1.5)

Ip = (0.8,0.8,0.8)

kd = (0,0,0.8)

### Resultado
![exerc_1_resultado](https://user-images.githubusercontent.com/49342589/89835981-2dbb6d00-db3c-11ea-88f1-e37a7a516a08.png)

## Exercício 2
### Definição 
O exercício 2 consistia em modificar o vertex shader do exercício anterior para incluir além dos dois modelos (ambiente e difuso), também o modelo especular. Para isto é necessário calcular dois vetores (R e V).

### Vetores Calculados
vec3 R = - reflect (L , N ) ;

vec3 V = normalize ( cam_pos - ( model_mat * vec4 ( obj_spc_vertex_pos , 1.0) ) .←- xyz ); 

### Modelo de Phong
I = Iaκa + Ip(κd *(L*N) + κs(R*V)^ n )

### Parâmetros
Ks = (1,1,1)

n = 64

### Resultado
![exerc_2_resultado](https://user-images.githubusercontent.com/49342589/89836383-06b16b00-db3d-11ea-853a-8da1acf1bfb6.png)


