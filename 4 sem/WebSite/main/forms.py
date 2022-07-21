from .models import Game, Film, Comic
from django.forms import ModelForm, TextInput, Textarea


class GameForm(ModelForm):
    class Meta:
        model = Game
        fields = ["user", "text"]
        widgets = {"user": TextInput(attrs={
            'class': 'form-control',
            'placeholder': 'Введите имя'
        }),
            "text": Textarea(attrs={
                'class': 'form-control',
                'placeholder': 'Введите текст'
            })
        }


class FilmForm(ModelForm):
    class Meta:
        model = Film
        fields = ["user", "text"]
        widgets = {"user": TextInput(attrs={
            'class': 'form-control',
            'placeholder': 'Введите имя'
        }),
            "text": Textarea(attrs={
                'class': 'form-control',
                'placeholder': 'Введите текст'
            })
        }


class ComicForm(ModelForm):
    class Meta:
        model = Comic
        fields = ["user", "text"]
        widgets = {"user": TextInput(attrs={
            'class': 'form-control',
            'placeholder': 'Введите имя'
        }),
            "text": Textarea(attrs={
                'class': 'form-control',
                'placeholder': 'Введите текст'
            })
        }
