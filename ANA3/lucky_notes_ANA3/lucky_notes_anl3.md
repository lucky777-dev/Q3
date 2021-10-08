# ANL3

[Intro](#étapes-de-développement-d'un-logiciel:)

## Étapes de développement d'un logiciel:
```
- Préétude
    - Analyse
        - Conception
            - Réalisation
                - Tests
                    - Déploiement
```
<img src="./sources/14_diagrammes.png" width="600" style="border: 2px solid black; display: block; margin: 0px auto 0px">
<p style="color: darkgray; text-align: center">Structure</p>

---

## Plan des différents diagrammes
```
Conceptuel:
    - MCD
        |---Diagramme de classe
        |---Docu
    - MCT
        |---Use Cases
        |---Docu
Fonctionnel:
    - UC Specification
        |---Diagramme d'activités
    - PTFE
        |---Docu
Technique:
    - MTD MTT
        |---Diagramme de séquence
        |---Diagramme de classe technique
```
---

## MCD
> Modèle conceptuel de données

Contenu:

- Packages
- Classes + Relations

<img src="./sources/structure_mcd.png" width="500" style="border: 2px solid black; display: block; margin: 0px auto 0px">
<p style="color: darkgray; text-align: center">Schéma MCD</p>

---

## MCT
> Modèle conceptuel de traitements

- Rôles et permissions
- Relations

<img src="./sources/structure_mct.png" width="500" style="border: 2px solid black; display: block; margin: 0px auto 0px">
<p style="color: darkgray; text-align: center">Schéma MCT</p>

---

### Use cases

> Cas d'utilisation

#### Objectifs:

- Définir les fonctionnalités du système
- Définir les limites précises du système

<img src="./sources/uc_exemple.png" width="300" style="border: 2px solid black; display: block; margin: 0px auto 0px">
<p style="color: darkgray; text-align: center">Schéma Use Cases</p>

#### Specifications:

```
- Documentation étendue
- Diagrammes d'activités
- Tests
     - Description brève du use cases
     - Description détaillée
         - Conditions (pré et post)
         - Flux (base + alternatif)
         - Exigences
```