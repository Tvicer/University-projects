from django.urls import path
from . import views

urlpatterns = [
    path('', views.index, name='home'),
    path('about', views.about, name='about'),
    path('game', views.game, name='game'),
    path('create_game', views.create_game, name='create_game'),
    path('film', views.film, name='film'),
    path('create_film', views.create_film, name='create_film'),
    path('comic', views.comic, name='comic'),
    path('create_comic', views.create_comic, name='create_comic'),
]