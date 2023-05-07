---
marp: true
theme: projet
paginate: true
_paginate: false
---

<script type="module">
  import mermaid from 'https://cdn.jsdelivr.net/npm/mermaid@10/dist/mermaid.esm.min.mjs';
    mermaid.initialize({ 
        startOnLoad: true,
        theme: 'base',
    });
</script>

<!--
# Style lead only for this slide
_class: lead
_footer: Algorithmique Avancée et Bibliothèque Graphique - 2022-2023
-->

![bg left](./images/fond_ece.png)

**ING1** Projet d'informatique


# ECE World

Equipe X

---

# Equipe X

![bg right:50%](./images/equipe.avif)

- Tata Jaja
- Toto Jojo
- Tyty Jyjy
- Tutu Juju
- Titi Jiji

---

# ECE World

![bg right:50% 198%](./images/theme.webp)

## Thème

Lorem ipsum dolor sit amet, **consectetur** adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. 

---

# Carte `1/2`

*Réalisée par : **Toto**, **Tata**.*

Décrire ici les fonctionnalités implémentées : choix joueurs, saisie des noms, affichage des scores/classement... Comment avez-vous fait ? Quels étaient les problèmes rencontrés.

---

# Carte `2/2`

Suite si ça ne tient pas sur une slide. 

:bulb: *Vous pouvez faire comme ça à chaque fois qu'une slide ne suffit pas, il vaut mieux 5 slides légères qu'une surchargée.*

---

# Organisation des jeux

Précisez comment les jeux sont organisés ? Sont-ils dans des fichiers séparés ? Dans des dossiers ? Sont-ils éparpillés dans plusieurs fichiers ?

Quels paramètres prennent les jeux ?  La file d'événement par exemple ? Ou est-ce que chaque jeu crée sa propre file ?

Comment on lance un jeu et comment on revient à la carte à la fin de la partie ?
Comment le classement est-il mis à jour ?


---

![bg right:40%](images/peche_canards.jpg)

# Pêche aux canards

*Réalisé par : **Toto** (40%), **Tata** (60%).*

Décrire le fonctionnement du jeu dans les grandes lignes. Comment vous l'avez conçu.
- Les canards vont de la droite à la gauche.
- Lorsqu'ils ont disparu, ils ont 1 chance sur 50 de réapparaitre à droite.
- Les canards vont à une vitesse différente (tirée aléatoirement).
- La collision des canards est détectée.
- etc.

<sup>:bulb: Remplacez les images par des captures d'écran de votre jeu.</sup>

---

![bg right:40%](images/peche_canards.jpg)

# Pêche aux canards

Pour chaque jeu (bien détailler au moins un jeu par personne), précisez les structures de données (structures importantes, tableaux importants, listes chainées...) et les fonctions importantes (avec leur prototype).

### Structures

<div class="mermaid">
%%{init: {'theme':'neutral'}}%%
classDiagram
    class Canard
    Canard : int x, y
    Canard : int vitesse
    class Canne
    Canne : int x, y
    Canne : Canard* canard
</div>

### Tableaux

- `Canard canards[20]`

---

![bg right:40%](images/peche_canards.jpg)

# Pêche aux canards

### Graphe d'appel

<br>

<div class="mermaid">
%%{init: {'theme':'neutral'}}%%
flowchart LR
    pecheAuxCanards --> initialiserCanards
    initialiserCanards --> positionnerCanard
    pecheAuxCanards --> deplacerCanards
    deplacerCanards --> deplacerCanard
    pecheAuxCanards --> detecterCollisionCanards
</div>


---

![bg right:40%](images/peche_canards.jpg)

# Pêche aux canards

### Logigramme

Que vous jugez pertinent (image ou Mermaid.js)



---

# Bilan collectif

---

<!--
_class: lead
-->

# Les slides suivantes ne seront pas présentées oralement lors de la soutenance mais doivent figurer dans la présentation. Nous les survolerons rapidement.

---

# Toto

## Tâches réalisées (pour chaque membre de l'équipe)

- `✅ 100%` Tâche 1
- `✅ 80%` Tâche 2
    - *Développer ici pourquoi cette tâche n'est pas terminée à 100%. (exemple : on aurait pu améliorer...).*
- `❌ 20%` Tâche 3
    - *Développer ici pourquoi cette tâche n'a pas été terminée.*
- `❌ 20%` Tâche 4
    - *Développer ici pourquoi cette tâche n'a pas été terminée.*
    - *Développer ici pourquoi cette tâche n'a pas été terminée.*

---

# Investissement

Si vous deviez vous répartir des points, comment feriez-vous ?

<div class="mermaid">
%%{init: {'theme':'neutral'}}%%
pie showData
    "Toto Jojo" : 20
    "Tata Jaja" : 20
    "Tyty Jyjy" : 10
    "Tutu Juju" : 40
    "Titi Jiji" : 10
</div>

---

# Récapitulatif des jeux

| Jeu | Avancement | Problèmes / reste |
| --- | --- | --- |
| Pêche aux canards | 100% | - |
| Tir aux ballons | 100% | - |
| Guitar Hero | 60% | Ne se synchronise pas avec la musique. Bug lors de l'appui sur deux touches en même temps (ne traite que la première note). |

Vous pouvez faire ce tableau sur plusieurs slides en dupliquant l'en-tête.

---

<!--
_class: lead
-->
# Quelques éléments que vous pouvez utiliser à votre guise dans votre présentation

---

# Schémas et Graphes

Vous pouvez utiliser [Mermaid.js](https://mermaid.js.org/) pour générer des schémas. Regardez la documentation.

---

# Slide avec du code


```C
for(int i = 0; i < 5; i++) {
    printf("%d ", i);
}
```

> 0 1 2 3 4 


---

# Emojis

https://gist.github.com/rxaviers/7360908

---

# Thème 

Vous pouvez personnaliser l'affichage de votre présentation avec le langage CSS en modifiant le fichier `theme.css`.

---

# Export PDF

Depuis récemment, l'export (**`Export Slide Deck...`**) en PDF oublie parfois des éléments. 
Si c'est le cas, nous vous conseillons d'exporter en fichier PowerPoint (pptx), puis de l'exporter en PDF depuis PowerPoint.

---

# Antoine 

- `✅ 100%` <u>__Jeux obligatoire</u> :__  Tir Au Ballon style
                Star Wars   🚀


- `✅ 99%` <u>__Map</u> :__ 
  - *Les colisions rendent la map un peu moins fluides.* 🌲


- `✅ 100%` <u>__Jeux Bonus </u>:__ Head Ball style Star Wars ⚽


---

# Tir Au Ballon  🎈🔫  `1/4`

### Les différentes textures :

- <u> Les Ballons </u> :
![bg right:40%](images/tete_strom.png)   ![bg right:80%](images/tete_vador.png)    ![bg right:40%](images/tete_yoda.png)

- <u>L'arme</u> : 

![](images/armegauche.png)

- <u>Les Gadgets</u> :

![](images/horloge.png)  ![](images/vaisseaumenu2.png)  ![](images/darkvador.png)

---

# Tir Au Ballon  🎈🔫  `2/4`

# Les fonctionnalitées ➕ :

  ➖ Mode de jeu Difficile : 91 ballons dans 3 zones 🚫
  
  ➖ Le jeu donne l'impression d'avoir de la 3D 🎲

  ➖ Colisions avec les bordures (diagonales), réaction des ballons aléatoires ⚡

  ➖ Apparitions et vitesse des ballons aléatoires 📡

  ➖ Son de tir et animations explosions ballons 💣

  ➖ Timer de 30 secondes par personnes. Les joueurs jouent l'un après l'autre 🕙

  ➖ Récap des scores et attributions des tickets 🎫

  ➖ Sauvegarde des meilleurs scores 💯

  ➖ Petite danse de Dark Vador 💃

---

# Tir Au Ballon  🎈🔫  `3/4`

## Capture d'écran de TirAuJedai : 

![](images/fondjeu.png)

---

# Tir Au Ballon  🎈🔫  `4/4`

## Structuration :


| Donnée                  | Structure                 | Code                                                                              |
|-------------------------|---------------------------|-----------------------------------------------------------------------------------|
| Images                  | Tableau d'ALLEGRO_BITMAP* | ``` ALLEGRO_BITMAP* image[50] ```                                                 |
| Appel images animations | Sprintf + for             | ``` for (int i=0;i<50;i++){ sprintf(char,"%d.png",i); al_load_bitmap(char); } ``` |
|                         |                           |                                                                                   |
|                         |                           |                                                                                   |
|                         |                           |                                                                                   |


---