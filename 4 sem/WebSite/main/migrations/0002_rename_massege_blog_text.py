# Generated by Django 4.0.3 on 2022-03-27 20:29

from django.db import migrations


class Migration(migrations.Migration):

    dependencies = [
        ('main', '0001_initial'),
    ]

    operations = [
        migrations.RenameField(
            model_name='blog',
            old_name='massege',
            new_name='text',
        ),
    ]
