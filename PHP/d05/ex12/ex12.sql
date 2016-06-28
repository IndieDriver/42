SELECT nom, prenom FROM fiche_personne
WHERE (nom LIKE '%-%' OR Prenom LIKE '%-%')
ORDER BY nom, prenom;
