<img width="150" height="150" alt="image" src="https://github.com/user-attachments/assets/e051cc7d-58b5-4e3e-926a-2fce4abe9293" />

## 🎮 Description

Philosophers est un projet de l’école 42 inspiré du célèbre problème des philosophes mangeurs formulé par
Edsger Dijkstra.
Ce projet a pour but de nous initier à la programmation concurrente et à la synchronisation des processus.

Dans la partie obligatoire, il s’agit d’implémenter une solution au problème en utilisant uniquement des
threads et des mutex.

---

## 🧩 Objectifs du projet

---

## 🧠 Concepts théoriques abordés

## 1. **Thread**
Un thread (ou fil d’exécution) est une unité d’exécution indépendante à l’intérieur d’un programme.
Plusieurs threads peuvent s’exécuter en parallèle dans un même processus et partager la même mémoire,
ce qui permet d’effectuer plusieurs tâches simultanément.

## 2. **Mutex**
Un mutex est un mécanisme de synchronisation qui empêche plusieurs threads d’accéder en même temps à
une même ressource partagée (comme une variable ou un fichier). Quand un thread verrouille un mutex,
les autres doivent attendre qu’il soit libéré avant d’y accéder.

## 3.**gettimeofday()**
La fonction `gettimeofday()` permet d’obtenir l’heure actuelle, exprimée en secondes et microsecondes
depuis l’époque UNIX (1er janvier 1970). Dans Philosophers, elle est utilisée pour mesurerle temps
écoulé depuis le début de la simulation et calculer les durées en millisecondes.

## 4.**usleep**
La fonction `usleep()` suspend l’exécution du thread courant pendant un certain nombre de microsecondes.
Elle est utilisée pour faire des pauses précises entre les actions des philosophes (par exemple, dormir
ou manger).
---

## ⚙️ Compilation, exécution et nettoyage

### 1. **Compilation**
Le projet se compile en utilisant la commande :
   
    make

### 2. **Exécution**
Pour lancer le programme, il faut utiliser la ligne de commande :

    ./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philo_must_eat]
Par exemple:

    ./philo 5 800 200 200 7

## 3. **Nettoyage**
Pour supprimer les fichiers objets et l’exécutable:

    make clean     # Supprime uniquement les fichiers objets (.o)
    make fclean    # Supprime les fichiers objets + l’exécutable cub3D
    make re        # Reconstruit complètement le projet

---

## ✨ Pour conclure
Bon courage et happy threading.🚀
Ce projet à été réaliser par mrosset.
