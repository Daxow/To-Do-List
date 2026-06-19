# td-cli

English below first, version française after.

***

## English

### Overview

`td-cli` is a lightweight terminal application for organizing todo tasks through an interactive command-line interface. It is designed for fast keyboard-driven task management with a minimal local setup.

### Features

- Interactive terminal UI.
- Keyboard-first navigation.
- Task creation and deletion.
- Task status updates.
- Task filtering for focused workflows.
- Simple build and run process.

### Installation

Clone the repository and build the project locally:

```bash
git clone https://github.com/Daxow/To-Do-List
cd To-Do-List
make -f ./makefile
```

### Usage

Run the application with:

```bash
./td-cli
```

This command opens the `td-cli` terminal user interface.

### Keyboard shortcuts

```text
[^v] Nav  [<>] Filtre  [c] Creer  [d] Suppr  [e] Statut  [h] Aide  [q] Quitter
```

### Controls

- `[^v]` Navigate through tasks.
- `[<>]` Filter the displayed tasks.
- `[c]` Create a new task.
- `[d]` Delete the selected task.
- `[e]` Change the task status.
- `[h]` Open the help screen.
- `[q]` Quit the application.

### Contributing

Contributions, ideas, and improvements are welcome through GitHub issues and pull requests. Please keep changes focused, documented, and aligned with the terminal-first design of the project.

### Contributors

- [Daxow](https://github.com/Daxow) — README and terminal design ideas.
- [clement444](https://github.com/clement444) — development of the task persistence system.
- [thomas-yv](https://github.com/thomas-yv) — code orchestrator, maintainer, and system designer.

### Repository

Project repository: [github.com/Daxow/To-Do-List](https://github.com/Daxow/To-Do-List)

***

## Français

### Présentation

`td-cli` est une application légère en terminal permettant d’organiser ses tâches via une interface interactive en ligne de commande. Le projet est pensé pour une gestion rapide au clavier avec une installation locale minimale.

### Fonctionnalités

- Interface terminal interactive.
- Navigation pensée pour le clavier.
- Création et suppression de tâches.
- Mise à jour du statut des tâches.
- Filtrage des tâches pour rester concentré.
- Processus simple de compilation et d’exécution.

### Installation

Clonez le dépôt puis compilez le projet localement :

```bash
git clone https://github.com/Daxow/To-Do-List
cd To-Do-List
make -f ./makefile
```

### Utilisation

Lancez l’application avec :

```bash
./td-cli
```

Cette commande ouvre l’interface terminal `td-cli`.

### Raccourcis clavier

```text
[^v] Nav  [<>] Filtre  [c] Creer  [d] Suppr  [e] Statut  [h] Aide  [q] Quitter
```

### Commandes

- `[^v]` Naviguer dans les tâches.
- `[<>]` Filtrer les tâches affichées.
- `[c]` Créer une nouvelle tâche.
- `[d]` Supprimer la tâche sélectionnée.
- `[e]` Modifier le statut d’une tâche.
- `[h]` Ouvrir l’aide.
- `[q]` Quitter l’application.

### Contribution

Les contributions, idées et améliorations sont les bienvenues via les issues et pull requests GitHub. Merci de proposer des changements ciblés, documentés et cohérents avec l’approche terminal-first du projet.

### Contributeurs

- [Daxow](https://github.com/Daxow) — README et idées autour du design du terminal.
- [clement444](https://github.com/clement444) — développement du système d’enregistrement des tâches.
- [thomas-yv](https://github.com/thomas-yv) — orchestrateur du code, maintainer et system designer.

### Dépôt

Dépôt du projet : [github.com/Daxow/To-Do-List](https://github.com/Daxow/To-Do-List)
