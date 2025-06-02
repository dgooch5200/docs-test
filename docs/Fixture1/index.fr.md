# Manuel d'utilisation du Projecteur 1

!!! attention
    Vous devez mettre à jour vers le dernier micrologiciel pour corriger ce problème !
    Veuillez utiliser UPLOAD02 ou USB-C pour effectuer la mise à jour

## Aperçu
Ce dépôt contient la documentation et les définitions de structure pour les différents enregistrements NDEF utilisés dans les produits CHAUVET. Chaque produit CHAUVET qui implémente la norme NFC NDEF indique la spécification et la version utilisées. Chaque enregistrement NDEF est versionné et documenté dans des fichiers séparés, avec un document maître `NDEF_Specification` qui suit la structure globale du message NDEF à travers les versions.

## Contenu
- `README.md` : Ce fichier, offrant un aperçu et des instructions sur la façon d'utiliser la documentation des normes.  
- `conf001.md`, `fixt001.md`, `logg001.md`, etc. : Fichiers de documentation individuels, détaillant la structure de chaque type d’enregistrement.  
- `NDEF_Structure_Type_1.md` : Le document principal suivant la structure des messages NDEF et l’historique des versions [Type 1].

## Comment utiliser cette documentation

### 1. Comprendre le message NDEF
Pour commencer, consultez le fichier `NDEF_Structure_Type_1.md`. Ce document fournit une répartition version par version de la structure du message NDEF, y compris les enregistrements inclus dans chaque version.

### 2. Travailler avec des enregistrements spécifiques
Chaque enregistrement NDEF utilisé dans les produits CHAUVET est documenté séparément :  
- Accédez au fichier d’enregistrement correspondant à la version avec laquelle vous travaillez (par exemple, `fixt001.md` pour la première version de l’enregistrement de projecteur).  
- Chaque fichier d’enregistrement fournit des informations détaillées sur les champs, leurs types de données, leurs tailles, et leur correspondance avec des adresses d’octet et de bloc spécifiques.  
- Les adresses de bloc et d’octet sont relatives au début de l’enregistrement en cours, l’octet initial étant à l’adresse `0x0000` et le bloc à `0x0000`.

### 2.5 Modèle 1
<model-viewer
  src="assets/Test.glb"
  alt="Modèle 3D"
  auto-rotate
  camera-controls
  shadow-intensity="1"
  environment-image="neutral"
  style="width: 100%; height: 400px;">
</model-viewer>

### 3. Gestion des versions
- **Versions d’enregistrement** : Lorsqu’une structure d’enregistrement est mise à jour, un nouveau fichier de version est créé (par exemple, `fixt002.md` après `fixt001.md`).  
- **Versions de propriété** : Lorsqu’une propriété est mise à jour, le numéro de version interne du document de propriété doit être incrémenté. Notez qu’un changement de version de propriété n’entraîne pas la mise à jour de la version de l’enregistrement.  
- **Versions du message NDEF** : À chaque évolution de la structure globale NDEF, le document `NDEF_Structure_Type_1.md` est mis à jour avec la nouvelle version. Toute mise à jour de version d’enregistrement ou de propriété y est également reflétée.  
- **Implémentation des nouveaux projecteurs** : Lorsque la spécification NDEF est mise à jour, la plupart des nouveaux projecteurs doivent être déployés avec la version la plus récente. Aucune exigence spécifique n’impose la mise à jour des équipements existants.  
- **Mise en œuvre de la nouvelle version de l’application** : Lorsque la spécification NDEF évolue, les applications doivent être mises à jour pour utiliser la nouvelle version. Elles doivent toujours pouvoir analyser les versions actuelles et antérieures de la spécification NDEF.

### 4. Mise en œuvre de la norme
- **Assurer la compatibilité** : Vérifiez que votre application ou appareil est compatible avec la spécification NDEF de CHAUVET.  
- **Se référer à la documentation** : Utilisez la structure détaillée présente dans chaque document d’enregistrement pour formater et analyser correctement les enregistrements NDEF.

### 5. Contribution à la norme
Si vous souhaitez contribuer ou proposer des modifications à cette norme :  
- Informez l’équipe de développement d’applications produits de CHAUVET de vos intentions.  
- Toutes les modifications doivent être proposées et examinées avant d’être mises en œuvre.

### 6. Micrologiciel
[Micrologiciel :material-arrow-right:](firmware/README.md){ .md-button }

??? astuce "Ceci n'est qu'un test ----- Notes :"
    Ceci n'est qu'un test!!!!

### 7. Quelque chose
hrerjelk j

### 8. Bloc de code
```mermaid
graph LR
  A[Début] --> B{Erreur ?};
  B -->|Oui| C[Hmm...];
  C --> D[Déboguer];
  D --> B;
  B ---->|Non| E[Youpi !];
