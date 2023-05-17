import PySimpleGUI as sg
import pymysql

if __name__ == '__main__':
    try:
        connection = pymysql.connect(
            host="localhost",
            user='root',
            password='1234',
            database='mydb'
        )
    except Exception as e:
        print(e)
        exit(-1)

    cursor = connection.cursor()

    sg.theme('DarkBlue')

    layoutAdd = [[sg.Text('Добавить чек:')],
                 [sg.Button('Добавить')]]
    layoutFindId = [[sg.Text('Поиск по чеков номеру')], [sg.Button('Поиск по номеру')]]
    layoutFind = [[sg.Text('Поиск по чеков дате')], [sg.Button('Поиск по дате')]]
    layoutDelete = [[sg.Text('Удалить чек')], [sg.Button('Удалить')]]

    window = sg.Window('Best Oil Base', (layoutAdd, layoutFindId, layoutFind, layoutDelete), size=(500, 260))

    while True:
        event, values = window.read()

        if event == sg.WIN_CLOSED:
            break

        if event == 'Добавить':
            cursor = connection.cursor()
            cursor.callproc('get_station')
            data = cursor.fetchall()
            station_id = []
            station_name = []
            cur_station_id = 0
            station_list = list(data)
            for row in station_list:
                station_id.append(row[0])
                station_name.append(row[1])

            cursor = connection.cursor()
            cursor.callproc('get_paymaster')
            data = cursor.fetchall()
            paymaster_id = []
            paymaster_name = []
            cur_paymaster_id = 0
            paymaster_list = list(data)
            for row in paymaster_list:
                paymaster_id.append(row[0])
                paymaster_name.append(row[1])

            cursor = connection.cursor()
            cursor.callproc('get_powerwasher')
            data = cursor.fetchall()
            powerwasher_id = []
            powerwasher_name = []
            cur_powerwasher_id = 0
            powerwasher_list = list(data)
            for row in powerwasher_list:
                powerwasher_id.append(row[0])
                powerwasher_name.append(row[1])

            layout = [
                [sg.Text('Введите данные:')],
                [sg.Text('Id чека:', size=(20, 1)), sg.InputText()],
                [sg.Text('Номер колонки:', size=(20, 1)), sg.InputText()],
                [sg.Text('Сколько литров залито:', size=(20, 1)), sg.InputText()],
                [sg.Text('Дата:', size=(20, 1)), sg.InputText()],
                [sg.Text('Номер заправки:', size=(20, 1)), sg.Combo(station_name, size=(43, 2))],
                [sg.Text('Кассир:', size=(20, 1)), sg.Combo(paymaster_name, size=(43, 2))],
                [sg.Text('Мойщик:', size=(20, 1)), sg.Combo(powerwasher_name, size=(43, 2))],
                [sg.Text('Id покупателя:', size=(20, 1)), sg.InputText()],
                [sg.Text('ФИО покупателя:', size=(20, 1)), sg.InputText()],
                [sg.Text('Возраст покупателя:', size=(20, 1)), sg.InputText()],
                [sg.Submit()]
            ]
            windowEntry = sg.Window('Добавление чека', layout, keep_on_top=True)

            while True:
                eventEntry, valuesEntry = windowEntry.read()

                if eventEntry == 'Submit':
                    cursor = connection.cursor()
                    try:
                        for i in range(len(station_name)):
                            if station_name[i] == valuesEntry[4]:
                                cur_station_id = i

                        for i in range(len(paymaster_name)):
                            if paymaster_name[i] == valuesEntry[5]:
                                cur_paymaster_id = i

                        for i in range(len(powerwasher_name)):
                            if powerwasher_name[i] == valuesEntry[6]:
                                cur_powerwasher_id = i

                        if valuesEntry[7] == '':
                            cursor.execute(
                                "insert into customer (customer_Id, customer_FIO, customer_Age) value (null, '{}', {})".format(
                                    valuesEntry[8], valuesEntry[9]))
                        else:
                            cursor.execute(
                                "insert into customer (customer_Id, customer_FIO, customer_Age) value ({}, '{}', {})".format(
                                    valuesEntry[7], valuesEntry[8], valuesEntry[9]))

                        if (valuesEntry[0] == '') and (valuesEntry[7] == ''):
                            cursor.execute(
                                "insert into bill (bill_Id, gas_station_Id, amount_of_fuel, "
                                "bill_date, station_station_Id, paymaster_paymaster_Id, customer_customer_Id,"
                                " powerwasher_powerwasher_Id) value (null, {}, {}, '{}', {}, {}, null, {})".format(
                                    valuesEntry[1], valuesEntry[2], valuesEntry[3],
                                    station_id[cur_station_id], paymaster_id[cur_paymaster_id],
                                    powerwasher_id[cur_powerwasher_id]))
                        else:
                            if valuesEntry[0] == '':
                                cursor.execute(
                                    "insert into bill (bill_Id, gas_station_Id, amount_of_fuel, "
                                    "bill_date, station_station_Id, paymaster_paymaster_Id, customer_customer_Id,"
                                    " powerwasher_powerwasher_Id) value (null, {}, {}, '{}', {}, {}, {}, {})".format(
                                        valuesEntry[1], valuesEntry[2], valuesEntry[3],
                                        station_id[cur_station_id], paymaster_id[cur_paymaster_id], valuesEntry[7],
                                        powerwasher_id[cur_powerwasher_id]))
                            else:
                                if valuesEntry[7] == '':
                                    cursor.execute(
                                        "insert into bill (bill_Id, gas_station_Id, amount_of_fuel, "
                                        "bill_date, station_station_Id, paymaster_paymaster_Id, customer_customer_Id,"
                                        " powerwasher_powerwasher_Id) value ({}, {}, {}, '{}', {}, {}, null, {})".format(
                                            valuesEntry[0], valuesEntry[1], valuesEntry[2], valuesEntry[3],
                                            station_id[cur_station_id], paymaster_id[cur_paymaster_id],
                                            powerwasher_id[cur_powerwasher_id]))
                                else:
                                    cursor.execute(
                                        "insert into bill (bill_Id, gas_station_Id, amount_of_fuel, "
                                        "bill_date, station_station_Id, paymaster_paymaster_Id, customer_customer_Id,"
                                        " powerwasher_powerwasher_Id) value ({}, {}, {}, '{}', {}, {}, {}, {})".format(
                                            valuesEntry[0], valuesEntry[1], valuesEntry[2], valuesEntry[3],
                                            station_id[cur_station_id], paymaster_id[cur_paymaster_id], valuesEntry[7],
                                            powerwasher_id[cur_powerwasher_id]))

                        connection.commit()
                        break
                    except (Exception, pymysql.DatabaseError) as error:
                        print(error)
                        sg.popup("Ошибка в транзакции! Отмена всех операций", keep_on_top=True)
                        connection.rollback()
                        break

                if eventEntry == sg.WIN_CLOSED:
                    break
                elif event == 'Date pop up':
                    sg.popup('You chose:', sg.popup_get_date())

            windowEntry.close()

        if event == 'Поиск по номеру':
            layout = [
                [sg.Text('Введите данные:')],
                [sg.Text('Id чека:', size=(5, 1)), sg.InputText()],
                [sg.Submit()]
            ]
            windowEntry = sg.Window('Поиск чека', layout, keep_on_top=True)

            while True:
                eventEntry, valuesEntry = windowEntry.read()

                if eventEntry == sg.WIN_CLOSED:
                    break
                elif event == 'Date pop up':
                    sg.popup('You chose:', sg.popup_get_date())

                if eventEntry == 'Submit':
                    windowEntry.close()
                    cursor = connection.cursor()

                    cursor.callproc('get_cur_bill', args=(valuesEntry[0]))
                    data = cursor.fetchall()
                    bill_list = []
                    for row in data:
                        bill_list.append(list(row))

                    cursor.callproc('get_food', args=(valuesEntry[0]))
                    data = cursor.fetchall()
                    name = ''
                    amount = ''
                    for row in data:
                        name += str(list(row)[0]) + '\n'
                        amount += str(list(row)[1]) + '\n'

                    bill_list[0].append(name)
                    bill_list[0].append(amount)

                    cursor.callproc('get_fastfood', args=(valuesEntry[0]))
                    data = cursor.fetchall()
                    name = ''
                    amount = ''
                    for row in data:
                        name += str(list(row)[0]) + '\n'
                        amount += str(list(row)[1]) + '\n'

                    bill_list[0].append(name)
                    bill_list[0].append(amount)

                    cursor.callproc('get_car_product', args=(valuesEntry[0]))
                    data = cursor.fetchall()
                    name = ''
                    amount = ''
                    for row in data:
                        name += str(list(row)[0]) + '\n'
                        amount += str(list(row)[1]) + '\n'

                    bill_list[0].append(name)
                    bill_list[0].append(amount)

                    headings = ['Номер чека', 'Номер колонки', 'Сколько литров залито',
                                'Дата', 'Кассир', 'ФИО покупателя', 'Мойщик', 'Еда', 'Кол-во', 'Фастфуд', 'Кол-во', 'Автомобильные запчасти', 'Кол-во']

                    layout = [[sg.Table(values=bill_list,
                                        headings=headings,
                                        max_col_width=20,
                                        auto_size_columns=True,
                                        display_row_numbers=True,
                                        justification='right',
                                        num_rows=5,
                                        alternating_row_color='black',
                                        key='-TABLE-',
                                        row_height=70)]]
                    windowView = sg.Window('Искомый чек', layout)

                    if windowView == sg.WIN_CLOSED:
                        break
                    elif event == 'Date pop up':
                        sg.popup('You chose:', sg.popup_get_date())

                    while True:
                        eventView, valuesView = windowView.read()
                        if eventView == sg.WIN_CLOSED:
                            break
                        elif event == 'Date pop up':
                            sg.popup('You chose:', sg.popup_get_date())

                        print(eventView, valuesView)

                    windowView.close()

            windowEntry.close()

        if event == 'Поиск по дате':
            date_list = []
            month_list = []
            year_list = []

            for i in range(32):
                date_list.append(i)

            for i in range(13):
                month_list.append(i)

            for i in range(1900, 2023):
                year_list.append(i)

            layout = [
                [sg.Text('Введите дату от:')],
                [sg.Text('День:', size=(5, 1)), sg.Combo(date_list, size=(20, 6))],
                [sg.Text('Месяц:', size=(5, 1)), sg.Combo(month_list, size=(20, 6))],
                [sg.Text('Год:', size=(5, 1)), sg.Combo(year_list, size=(20, 6))],
                [sg.Text('Введите дату до:')],
                [sg.Text('День:', size=(5, 1)), sg.Combo(date_list, size=(20, 6))],
                [sg.Text('Месяц:', size=(5, 1)), sg.Combo(month_list, size=(20, 6))],
                [sg.Text('Год:', size=(5, 1)), sg.Combo(year_list, size=(20, 6))],
                [sg.Submit()]
            ]
            windowEntry = sg.Window('Поиск чека', layout, keep_on_top=True)

            while True:
                eventEntry, valuesEntry = windowEntry.read()

                if eventEntry == sg.WIN_CLOSED:
                    break
                elif event == 'Date pop up':
                    sg.popup('You chose:', sg.popup_get_date())

                if eventEntry == 'Submit':
                    windowEntry.close()
                    cursor = connection.cursor()

                    cursor.callproc('get_bill_of_date', args=('{}-{}-{}'.format(
                        valuesEntry[2], valuesEntry[1], valuesEntry[0]),
                                                              '{}-{}-{}'.format(
                                                                  valuesEntry[5], valuesEntry[4], valuesEntry[3])
                    ))
                    data = cursor.fetchall()
                    bill_list = []
                    for row in data:
                        bill_list.append(list(row))

                    headings = ['Номер чека', 'Номер колонки', 'Сколько литров залито',
                                'Дата', 'Кассир', 'ФИО покупателя', 'Мойщик']

                    layout = [[sg.Table(values=bill_list,
                                        headings=headings,
                                        max_col_width=35,
                                        auto_size_columns=True,
                                        display_row_numbers=True,
                                        justification='right',
                                        num_rows=7,
                                        alternating_row_color='black',
                                        key='-TABLE-',
                                        row_height=35)]]
                    windowView = sg.Window('Искомый чек', layout)

                    if windowView == sg.WIN_CLOSED:
                        break
                    elif event == 'Date pop up':
                        sg.popup('You chose:', sg.popup_get_date())

                    while True:
                        eventView, valuesView = windowView.read()
                        if eventView == sg.WIN_CLOSED:
                            break
                        elif event == 'Date pop up':
                            sg.popup('You chose:', sg.popup_get_date())

                        print(eventView, valuesView)

                    windowView.close()

            windowEntry.close()


        if event == 'Удалить':
            layout = [
                [sg.Text('Введите данные:')],
                [sg.Text('Id чека:', size=(5, 1)), sg.InputText()],
                [sg.Submit()]
            ]
            windowEntry = sg.Window('Удалить чек', layout, keep_on_top=True)

            while True:
                eventEntry, valuesEntry = windowEntry.read()

                if eventEntry == sg.WIN_CLOSED:
                    break
                elif event == 'Date pop up':
                    sg.popup('You chose:', sg.popup_get_date())

                if eventEntry == 'Submit':
                    cursor = connection.cursor()
                    try:
                        cursor.execute("delete from bill where bill_Id = {}".format(valuesEntry[0]))
                        connection.commit()
                        break
                    except (Exception, pymysql.DatabaseError) as error:
                        print(error)
                        sg.popup("Ошибка в транзакции! Отмена всех операций", keep_on_top=True)
                        connection.rollback()
                        break


            windowEntry.close()

    connection.close()
    window.close()
