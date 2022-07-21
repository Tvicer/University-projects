from django.db import models


class Game(models.Model):
    user = models.CharField('Имя пользователя', max_length=30)
    text = models.TextField('Текст')

    def __str__(self):
        return self.user


class Film(models.Model):
    user = models.CharField('Имя пользователя', max_length=30)
    text = models.TextField('Текст')

    def __str__(self):
        return self.user


class Comic(models.Model):
    user = models.CharField('Имя пользователя', max_length=30)
    text = models.TextField('Текст')

    def __str__(self):
        return self.user
