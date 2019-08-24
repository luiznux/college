//Este programa recebe uma entrada de texto do usuario e devolve uma resposta do provavel idioma que ele escreveu seu texto,//
// interpretando os idiomas alemao, portugues e ingles//
//
//Utilizando vetores com dados de frequencias das letras em cada idioma(sem considerar acentos ou caracteres especiais
//Comparo a entrada do usuario com a letras, apos isso verifico sua ocorrencia, assim cada valor sera acrecentado a uma 
//pontuação,quem tiver a maior, sera o idioma de resposta//

char alfabeto[26] = [a,b,c,d,e,,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z];

double  alfabeto_ingles = [8.16, 1.49, 2.78, 4.25, 12.70, 2.22, 2.01, 6.09, 6.96, 0.15, 0.77, 4.02, 2.40, 6.74, 7.50, 1.92, 0.09, 5.98, 6.32, 9.05, 2.75, 0.97, 2.36,  0.15, 1.97, 0.07];

double alfabeto_portugues = [14.63, 1.04, 3.88, 4.99, 12.57, 1.02, 1.30, 1.28, 6.18, 0.40, 0.02, 2.78, 4.74, 5.05, 10.73, 2.52, 1.20, 6.53, 7.81, 4.34, 4.63, 1.67, 0.01, 0.21, 0.01, 0.47];

double alfabeto_alemao = [6.51, 1.89, 3.06, 5.08, 17.40, 1.66, 3.01, 4.76, 7.55, 0.27, 1.21, 3.44, 2.53, 9.78, 2.51, 0.79, 0.02, 7.00, 7.27, 6.15, 4.35, 0.67, 1.89, 0.03, 0.04, 1.13];

double pontos_portugues = 0;
double pontos_alemao = 0; 
double pontos ingles = 0;

char texto_usuario;

printf("Digite uma texto sem caracteres sem acentos ")scanf(" %s", texto_usuario);

