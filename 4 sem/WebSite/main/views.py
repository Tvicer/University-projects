from django.shortcuts import render, redirect
from .models import Game, Film, Comic
from .forms import GameForm, FilmForm, ComicForm
from django.http import HttpResponseNotFound


def index(request):
    return render(request, 'main/index.html', {'title': 'Главная страница'})


def about(request):
    return render(request, 'main/about.html', {'title': 'Про автора'})


def game(request):
    games = Game.objects.order_by('-id')
    return render(request, 'main/game.html', {'title': 'Про игры', 'games': games})


def create_game(request):
    error = ''
    if request.method == 'POST':
        form = GameForm(request.POST)
        if form.is_valid():
            form.save()
            return redirect('game')
        else:
            error = 'Ошибка!'
    form = GameForm()
    context = {'form': form, 'error': error}
    return render(request, 'main/create_game.html', context)


def film(request):
    films = Film.objects.order_by('-id')
    return render(request, 'main/film.html', {'title': 'Про фильмы', 'films': films})


def create_film(request):
    error = ''
    if request.method == 'POST':
        form = FilmForm(request.POST)
        if form.is_valid():
            form.save()
            return redirect('film')
        else:
            error = 'Ошибка!'
    form = FilmForm()
    context = {'form': form, 'error': error}
    return render(request, 'main/create_film.html', context)


def comic(request):
    comics = Comic.objects.order_by('-id')
    return render(request, 'main/comic.html', {'title': 'Про комиксы', 'comics': comics})


def create_comic(request):
    error = ''
    if request.method == 'POST':
        form = ComicForm(request.POST)
        if form.is_valid():
            form.save()
            return redirect('comic')
        else:
            error = 'Ошибка!'
    form = ComicForm()
    context = {'form': form, 'error': error}
    return render(request, 'main/create_comic.html', context)


def page_not_found(request, exception):
    return HttpResponseNotFound('<h1>Страница не найдена :(</h1><br><h1>Та самая ошибка 404</h1>')
