# td-cli

Une application légère en terminal pour organiser, parcourir et mettre à jour ses tâches à travers une interface interactive en ligne de commande.

## Présentation

`td-cli` est un outil de gestion de tâches pensé pour les usages centrés sur le terminal. Il propose une interface textuelle compacte pour naviguer dans les tâches, filtrer la liste, créer des entrées, supprimer des éléments et mettre à jour leur statut.

## Fonctionnalités

- Interface terminal interactive pour la gestion quotidienne des tâches.
- Navigation rapide entièrement pensée pour le clavier.
- Création et suppression de tâches depuis l’interface principale.
- Mise à jour du statut des tâches directement depuis le CLI.
- Filtrage des tâches pour se concentrer sur l’essentiel.
- Installation locale simple avec `make`.

## Installation

Clonez le dépôt puis compilez le projet localement :

```bash
git clone https://github.com/Daxow/To-Do-List
cd To-Do-List
make -f ./makefile
```

## Utilisation

Lancez l’application avec :

```bash
./td-cli
```

Cette commande ouvre l’interface utilisateur terminal de `td-cli`.

## Raccourcis clavier

```text
[^v] Nav  [<>] Filtre  [c] Creer  [d] Suppr  [e] Statut  [h] Aide  [q] Quitter
```

## Commandes

- `[^v]` Naviguer dans les tâches.
- `[<>]` Filtrer les tâches affichées.
- `[c]` Créer une nouvelle tâche.
- `[d]` Supprimer la tâche sélectionnée.
- `[e]` Modifier le statut d’une tâche.
- `[h]` Ouvrir l’aide.
- `[q]` Quitter l’application.

## Développement

Ce projet repose sur un flux de compilation basé sur un `makefile`. Après avoir cloné le dépôt, exécutez la commande de compilation puis lancez le binaire généré depuis la racine du projet.

## Contribution

Les contributions, idées et améliorations sont les bienvenues via les issues et pull requests GitHub. Merci de proposer des changements ciblés, documentés et cohérents avec l’approche terminal-first du projet.

## Contributeurs

- [Daxow](https://github.com/Daxow) — README et idées autour du design du terminal.
- [clement444](https://github.com/clement444) — développement du système d’enregistrement des tâches.
- [thomas-yv](https://github.com/thomas-yv) — orchestrateur du code, maintainer et system designer.

## Dépôt

Dépôt du projet : [github.com/Daxow/To-Do-List](https://github.com/Daxow/To-Do-List)

## Licence

Ajoutez ici la licence du projet si elle est disponible dans le dépôt.
