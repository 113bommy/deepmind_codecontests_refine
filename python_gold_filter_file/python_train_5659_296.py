#Вася работает диджеем в самом лучшем ночном клубе Берляндии, и часто в своих выступлениях он использует музыку
# в стиле «дабстеп». Недавно он решил взять несколько старых песен и сделать из них дабстеп-ремиксы.

#Пусть песня состоит из некоторого количества слов. Для того, чтобы сделать дабстеп-ремикс этой песни,
# Вася вставляет некоторое количество слов «WUB» до первого слова песни (возможно нулевое количество), после последнего
# слова (возможно нулевое количество) и между словами (между любой парой соседних слов песни хотя бы одно слово «WUB»),
# а затем склеивает все слова, включая «WUB», в одну строку и проигрывает в клубе.

#Например, из песни со словами «I AM X» может получиться дабстеп-ремикс «WUBWUBIWUBAMWUBWUBX» и не может получиться
# дабстеп-ремикс «WUBWUBIAMWUBX».

#Недавно Петя услышал новую дабстеп-композицию Васи, но так как он не очень любит современную музыку,
#то решил понять, из какой же песни Вася сделал свой ремикс. Помогите Пете восстановить оригинал.

s = input().split('WUB')
i  = 0
S = []
while i < len(s):
    if s[i] != '':
        S.append(s[i])
        i += 1
    else:
        i += 1
for i in S:
    print(i)