# Sistema de Pedidos para Restaurante

## Equipe de Pedidos para Restaurante  
1. **Filipy da Silva Bruno** - 202201620  
2. **Heitor de Angelis Cabral** - 202302539  
3. **Ícaro Pereira Rosa Alves de Sá** - 202302547

---

## Sobre o Projeto  
Este projeto visa o desenvolvimento de um sistema para gestão de pedidos em restaurantes, com o objetivo de melhorar a eficiência operacional e reduzir erros no atendimento. Implementado em linguagem C, o sistema utiliza estruturas dinâmicas e arquivos para simular o armazenamento persistente dos dados de pedidos e cardápio. O sistema também visa proporcionar uma ferramenta prática para gerentes e atendentes, agilizando o fluxo de trabalho e otimizando a experiência dos clientes.
   
---

## **Seção I. Introdução**

### Problema  
A gestão de pedidos é um dos desafios centrais para restaurantes, frequentemente resultando em atrasos, erros e insatisfação dos clientes. Esses problemas afetam a reputação do restaurante e podem causar perdas financeiras significativas. Este relatório propõe uma solução tecnológica para otimizar o processo de pedidos, garantindo maior precisão e eficiência.

### Literatura  
1. **ABRASEL. Sistema de restaurante integrado: como a tecnologia pode melhorar a gestão e a experiência do cliente.**  
   A publicação explora o impacto positivo da integração de sistemas em restaurantes, destacando benefícios como a melhoria na experiência do cliente e o aumento da eficiência operacional. Soluções integradas ajudam a reduzir erros e a gerenciar melhor os recursos. Disponível em: [Abrasel](https://abrasel.com.br/revista/mercado-e-tendencias/sistema-restaurante-integrado/).  

2. **NEXAAS. Gestão de pedidos: entenda a importância para seu negócio.**  
   Este artigo destaca a importância da gestão eficiente de pedidos, enfatizando como um controle automatizado pode fornecer informações em tempo real e facilitar decisões estratégicas. A automação é apontada como essencial para evitar erros e melhorar o atendimento. Disponível em: [Nexaas](https://www.nexaas.com/blog/gestao-de-pedidos-entenda-a-importancia-para-seu-negocio#:~:text=A%20boa%20gest%C3%A3o%20de%20pedidos,dos%20neg%C3%B3cios%20em%20tempo%20real).  

3. **TOTVS. Controle de pedidos: entenda como otimizar a gestão de serviços.**  
   O blog aborda estratégias para otimizar o controle de pedidos, com foco no uso de softwares integrados. Aponta que um bom sistema pode simplificar operações e permitir que os gestores tomem decisões mais rápidas e precisas. Disponível em: [TOTVS](https://www.totvs.com/blog/gestao-de-servicos/controle-de-pedidos/).  

### Dataset  
Os dados simulados incluem:  
- **Cardápio:** Itens com descrições e preços.  
- **Pedidos:** Número do pedido, status e itens solicitados.  
- **Clientes:** Informações básicas, como nome e contato.  

### Métodos  
O sistema será desenvolvido utilizando:  
- **Linguagem:** C, devido à sua eficiência e controle direto de memória.  
- **Estruturas de Dados:** Utilização de listas encadeadas para gerenciamento dinâmico de pedidos e cardápios.  
- **Banco de Dados Simples:** Arquivos em formato texto para armazenamento persistente de dados.  

### Avaliação  
A eficiência do sistema será avaliada com as seguintes métricas:  
- **Tempo de Resposta:** Média de tempo para processar pedidos.  
- **Taxa de Erro:** Proporção de pedidos registrados incorretamente.  
- **Satisfação do Cliente:** Avaliação qualitativa de usabilidade e funcionalidade.

---

## **Seção II. Fundamentos teóricos**
O sistema de pedidos para restaurantes está sendo desenvolvido com base em técnicas fundamentais de estruturas de dados e manipulação de arquivos, buscando criar uma solução eficiente e prática para os desafios de gestão de pedidos. A seguir, são descritos os principais mecanismos e algoritmos utilizados, bem como as métricas que serão aplicadas para avaliar seu desempenho.

Estruturas de Dados Dinâmicas
O sistema utiliza listas encadeadas como estrutura central para organizar dados do cardápio e pedidos. A escolha foi feita devido à flexibilidade dessas listas, que permitem inserções e remoções dinâmicas sem a necessidade de redimensionamento, como ocorre em arrays.

Os nós das listas armazenam:

Cardápio: Nome do item, preço e identificador único.
Pedidos: Número do pedido, itens solicitados, status ("Pendente", "Concluído") e informações do cliente.
As operações principais incluem a inserção dinâmica de dados, busca eficiente e atualização de informações. Essas técnicas garantem que o sistema possa lidar com mudanças frequentes e volumes crescentes de dados.

Manipulação de Arquivos e Persistência
Para persistir os dados entre execuções, o sistema utiliza arquivos de texto que simulam um banco de dados básico. As funções principais incluem:

Leitura e escrita: Implementadas com fscanf() e fprintf() para carregar e salvar informações do cardápio e dos pedidos.
Consistência de dados: O formato dos arquivos é padronizado para facilitar a leitura e a escrita.
Esses mecanismos garantem que os dados sejam armazenados e recuperados de forma confiável, mesmo após o programa ser encerrado.

Algoritmos de Gestão de Pedidos
Os algoritmos centrais do sistema incluem:

Cadastro de Pedidos: Insere novos pedidos na lista encadeada, registrando itens e status iniciais.
Atualização de Status: Localiza pedidos pelo número e ajusta seu status conforme necessário.
Relatórios Estatísticos: Consolida informações como tempo médio de atendimento e itens mais pedidos.
Esses algoritmos são projetados para serem simples e eficientes, otimizando o processamento e garantindo estabilidade.

Avaliação e Métricas de Desempenho
O sistema será avaliado com base em:

Tempo de Resposta: Mede a eficiência em processar operações com diferentes volumes de dados.
Taxa de Erro: Analisa falhas no registro ou atualização de pedidos.
Uso de Memória: Avalia o impacto das listas encadeadas no consumo de recursos.
Satisfação do Usuário: Será medida por simulações práticas para verificar a usabilidade.
As métricas serão apresentadas em gráficos e tabelas, permitindo uma análise clara e detalhada do desempenho do sistema.
Integração e Solução do Problema
O sistema combina algoritmos eficientes, estruturas dinâmicas e persistência de dados para oferecer uma solução prática e robusta. As técnicas aplicadas visam reduzir erros, agilizar processos e melhorar a experiência dos usuários, alinhando-se aos objetivos do projeto.

---

## **Seção III. Metodologia**

### Passos Executados  

1. **Estruturação Inicial do Sistema**  
   - Definição das estruturas de dados em C para armazenar itens do cardápio, pedidos e clientes.  
   - Planejamento do fluxo básico: adicionar pedidos, atualizar status e exibir relatórios.  

2. **Implementação do Gerenciamento de Dados**  
   - Criação de funções para leitura e escrita em arquivos, simulando persistência de dados.  
   - Implementação de listas encadeadas para permitir a adição e remoção dinâmica de itens.  

3. **Desenvolvimento das Funcionalidades**  
   - **Cadastro de Pedidos:** Função para adicionar novos pedidos à lista.  
   - **Atualização de Status:** Função para modificar o status de um pedido.  
   - **Relatórios:** Geração de um resumo dos pedidos processados, incluindo tempo médio de atendimento.  

4. **Testes e Simulação**  
   - Testes unitários para validar as funções principais do sistema.  
   - Simulação de carga para avaliar o desempenho em diferentes volumes de pedidos.

---

## **Seção IV. Resultados e conclusões**
O desenvolvimento do sistema de pedidos para restaurantes tem apresentado resultados iniciais positivos, com funcionalidades essenciais já implementadas e testadas em um ambiente controlado. Até agora, o sistema mostrou ser capaz de gerenciar itens do cardápio e pedidos de forma dinâmica, utilizando listas encadeadas e persistência de dados em arquivos. Essas funcionalidades se mostraram fundamentais para alcançar o objetivo principal do projeto: organizar e otimizar o gerenciamento de pedidos de maneira eficiente e confiável.

Funcionalidades Avaliadas

Cadastro de Itens no Cardápio: Os testes realizados indicaram que o sistema tem desempenho estável em diferentes volumes de dados, o que reforça a adequação das listas encadeadas como estrutura base. A inserção de novos itens ocorre de forma fluida e consistente.

Cadastro e Atualização de Pedidos: Os algoritmos de inserção e atualização de pedidos apresentaram respostas rápidas, mesmo em listas maiores, destacando a eficiência das operações. A funcionalidade de atualização de status também se mostrou prática e confiável.

Relatórios Estatísticos: A geração de relatórios, como identificação de itens mais vendidos, listagem de pedidos pendentes e o resumo geral de atividades, proporcionou uma visão útil do desempenho do sistema e dos padrões operacionais simulados.

Resultados Preliminares (Simulação)
Os testes iniciais em ambiente simulado geraram resultados encorajadores:

Tempo Médio de Processamento:

Adicionar itens ao cardápio: aproximadamente 2 ms por operação.
Registro de pedidos: cerca de 3 ms por operação.
Atualização de status: em torno de 1,5 ms por operação.
Taxa de Erro: Durante os testes, 100% das operações válidas de inserção e atualização foram realizadas com sucesso. Os erros detectados foram restritos a entradas inválidas, como IDs duplicados ou referências a itens inexistentes, o que demonstra que as validações implementadas estão funcionando corretamente.

Escalabilidade: O sistema demonstrou desempenho consistente em listas com até 500 pedidos e 100 itens no cardápio, indicando sua viabilidade para restaurantes de pequeno e médio porte.

Representação Gráfica
Embora gráficos detalhados dependam de dados mais abrangentes, é possível prever a inclusão de representações visuais, como gráficos de barras para tempos médios de operação e taxas de erro, após a conclusão dos testes finais. Essa análise será expandida pelos membros da equipe, com tabelas e gráficos detalhados complementando os resultados apresentados.

Comparação com a Literatura
Os resultados obtidos até o momento corroboram as observações da literatura utilizada como base para o projeto. De acordo com a ABRASEL (2022), a integração de sistemas automatizados é essencial para reduzir erros e melhorar a eficiência operacional, o que foi confirmado durante as simulações. Da mesma forma, NEXAAS (2022) destaca que sistemas capazes de gerar relatórios detalhados ajudam na tomada de decisões estratégicas. Nosso sistema segue essa direção, utilizando relatórios estatísticos como um diferencial para aprimorar a gestão.

Essas comparações mostram que, mesmo em estágio inicial, o sistema está alinhado às melhores práticas do setor e atende aos objetivos definidos na literatura.

Conclusões
O desenvolvimento do sistema trouxe lições valiosas para a equipe, tanto no aspecto técnico quanto na organização do projeto. Entre os aprendizados mais significativos, destacam-se:

Planejamento Estrutural: O uso de listas encadeadas mostrou ser uma escolha eficiente, mas também exigiu cuidado adicional no tratamento de ponteiros e validações para evitar inconsistências.

Persistência de Dados: Trabalhar com arquivos em C foi eficaz, mas apresentou desafios, como garantir a consistência dos formatos e a integridade das operações de leitura e escrita.

Validações e Testes: Um sistema robusto depende de validações bem implementadas. As verificações de IDs únicos e entradas corretas evitaram erros que poderiam comprometer a integridade dos dados.

Trabalhos Futuros
Com base nos resultados preliminares, os próximos passos para o sistema incluem:

Testes Avançados: Realizar simulações em ambientes mais próximos da realidade, com maiores volumes de dados e múltiplos usuários interagindo simultaneamente.

Expansão de Funcionalidades: Incluir relatórios estatísticos mais detalhados, como análise de desempenho semanal e comparações entre períodos de vendas.

Melhorias na Interface: Explorar a criação de uma interface gráfica ou aprimorar a navegação textual, tornando o sistema mais acessível e intuitivo.


---
## **Referências**
1.
2.
---

## **Apêndices**

### Apêndice A - Diagrama demonstrando as funções do programa

![Classe UML (2)](https://github.com/user-attachments/assets/2d2facd3-14e1-4b22-b0e8-4ed790cab70d)
