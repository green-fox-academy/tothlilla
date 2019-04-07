/*DROP DATABASE ToDo;*/

CREATE DATABASE IF NOT EXISTS todo;
USE todo;

CREATE TABLE IF NOT EXISTS ToDo
(
	storyID INTEGER UNSIGNED NULL
);

CREATE TABLE IF NOT EXISTS Doing
(
	storyID INTEGER UNSIGNED NULL
);

CREATE TABLE IF NOT EXISTS Review
(
	storyID INTEGER UNSIGNED NULL
);

CREATE TABLE IF NOT EXISTS Done
(
	storyID INTEGER UNSIGNED NULL
);

CREATE TABLE IF NOT EXISTS Story
(
	storyID INTEGER UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY,
    storyText TEXT
);

INSERT INTO Story (storyText)
VALUES ("shopping"),("cleaning"),("cooking"), ("study");

INSERT ToDO (storyID)
SELECT storyID FROM Story
WHERE storyTEXT = "shopping";

INSERT ToDO (storyID)
SELECT storyID FROM Story
WHERE storyTEXT = "study";

INSERT  Done (storyID)
SELECT storyID FROM Story
WHERE storyTEXT = "cleaning";

SELECT storyTEXT AS TODO FROM ToDo
INNER JOIN Story
ON story.storyID = ToDo.storyID; 

SELECT storyTEXT AS DOING FROM Doing
INNER JOIN Story
ON story.storyID = Doing.storyID;

SELECT storyTEXT AS REVIEW FROM Review
INNER JOIN Story
ON story.storyID = Review.storyID; 

SELECT storyTEXT AS DONE FROM Done
INNER JOIN Story
ON story.storyID = Done.storyID; 

/*DROP DATABASE ToDo;*/


