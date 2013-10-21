1. num = int(raw_input('insira um numero'))
    exp = 0
    while 2**exp<num :
       print 2**exp
       exp += 1

--------------------------------------------------------------
2. num = int(raw_input('insira um numero'))

    div = 0
    while num%div = 0
       div += 1
   print consegue dividir em : , div

------------------------------------------------------------------
3.num = int(raw_input('insira um numero'))

  soma = 0
  div = 2

  while div < num : 
          if num %div == 0:
          soma += div
          div += 1
         
  print 'resultado', soma

-----------------------------------------------------------------

4. num = int(raw_input('insira um numero'))
  
  soma = 0
  div = 2

  while div < num : 
          if num %div == 0:
          soma += div
          div += 1
          print 'soma dos divisores proprios', soma
  if num = soma + 1 : 
          print 'eh perfeito'
  else:
          print ' nao eh perfeito'

-----------------------------------------------------------------
5.num = int(raw_input('Insira um numero'))

ePrimo = True   
div = 1
while num < div and ePrimo : 
         if  num % div == 0 : 
             ePrimo = False
         div += 1
if ePrimo:
         print 'o numero eh primo'
else:
         print 'o numero n eh primo'

-----------------------------------------------------------------
// folha 4
1. a)
num=int (raw_input('insira um numero'))

div = 1
soma = num

while num/2>= div:
        if  num % div == 0
            soma += div
        div += 1
print 'a soma dos disivsores eh' , soma
-----------------------------------------------------------------------

1. b) /* no ciclo for a parte do in range percorre todos os numeros menos o ultimo...
ou seja de 0 a 10 so vai ate 9*/

num = int(raw_input('insira um numero'))

soma = num

for div = 1 in range (1, num/2 + 1 )
    num % div ==0
    soma += div
print 'A soma dos divisores eh', soma    

------------------------------------------------------------

3.

num = int(raw_input('insira um numero'))
// my way
fact = 0

for 0<div = num in range ( 0, num +1):
    fact = num % div
    print fact
    div -= 1
    
    --------
//prof way    
fact = 1
for mult in range (2, num+1):
    fact *= mult
print ' o factorial eh', fact    
    

-----------------------------------------------------------

4.

num = int(raw_input('insira um numero'))
      
soma = 0

for i in range (1, num+1, 2):
    soma +=1
print 'A soma dos impares eh', soma


-----------------------------------------------------------

5.

num = float(raw_input('insira um numero'))

inf = min (-1, num)

sup = max (1,num)

eno = 0.0001

tent = (sup+inf) / 2.0

while abs(tent**3 - num)<eno
      if tent**3 > num:
          sup = tent
      else
          inf = tent
      tent = (sup + inf) / 2.0
      print 'A raiz cubica eh proxima de', tent
      
      
      
-------------------------------------------------------

//folha 5

1.

def succ (num):
    """ requer que num seja um int bastando apenas fazer succ (num inteiro) tipo succ(2)
        devolve um int que corresponde ao incremento de num em uma unidade """
    return num + 1

     """ na altura da compilação é necessario chamar a função fazendo
         succ(10), pode-se consultar os comentarios das funçoes na consola atravez
         do comando help(succ)"""
         
         
------------------------------------------------------------------


2.

def maior2 (num1, num2):
    """requer que num seja um int
       devolve um int que corresponde
       ao maior entre os dois"""
       if num1<num2:
        maior2 = num2
       else num1>num2:
        maior2 = num1
    return maior2


// para acabar a função escreve se maior2 ( 10,20)
---------------------------------------------------------------

3.

def maior3 (num1, num2, num3):
    """requer que num seja um int
       devolve um int que corresponde
       ao maior entre os tres"""
       if num1<num2<num3:
        maior = num3
       elif num2>num1>num3:
        maior = num2
       else
        maior = num1
    return maior
    ------ou------
    maior = maior2 (num1,num2)
    return mior2 (maior, num3)
    ------ou------
    return maior2 (num1,num2),num3)
      
// para acabar/executar a função escreve-se maior(10,20,15)    
     
----------------------------------------------------------------------

4.      
      
 def direita (num)
    """ requer que  num seja inte
        devolve um int correspondente
        a unidade mais a direita"""
        while num % 10 :
        direita = num
        return num
      
      
------------------------------------------------------------------------

5. 

 def elimina (num)
    """requer que num seja int
       devolve um int correspondente
       mas sem as unidades"""
       return num/10
-----------------------------------------------------------------

6.

 def aumenta (num)
    """aumenta o numero int"""
    return num * 10
--------------------------------------------------------------------

7.

def ecapicua (num)
    """ requer que o num seja inteiro
        e se a escrita normal for igual a
        escrita inversa entao return true or false"""
        original = num
        while num > 0
           digito = direita (num)
           invertido = digito
           num = elimina (num)
           
        return original == invertido

            
        
        
       
       
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
    
