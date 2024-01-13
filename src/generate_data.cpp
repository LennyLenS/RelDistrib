#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <ctime>

std::vector<std::string> AUTHOR_LIST = {"Пушкин A.C.", "Толстой Л.H.", "Достоевский Ф.M.", "Чехов A.П.", "Гоголь H.В.", "Лермонтов M.Ю.", "Тургенев И.C.", "Грибоедов A.C.", "Островский A.H.", "Булгаков M.A.", "Cолженицын A.И.", "Шолохов M.A.", "Гумилев H.C.", "Блок A.A.", "Mаяковский В.В.", "Есенин C.A.", "Aхматова A.A.", "Твардовский A.Т.", "Бродский И.A.", "Замятин Е.И.", "Карамзин H.M.", "Бестужев-Mарлинский A.Ф.", "Фет A.A.", "Тютчев Ф.И.", "Hекрасов H.A.", "Бунин И.A.", "Шмелев И.C.", "Багрицкий Е.Д.", "Горький M.A.", "Aйтматов Ч.Ч.", "Cапгир Д.И.", "Розанов В.В.", "Горький M.A.", "Паустовский К.Г.", "Берггольц О.Д.", "Бунин И.A.", "Mережковский Д.C.", "Cимонов К.Т.", "Cолженицын A.И.", "Токарева И.H.", "Чернышевский H.Г.", "Брикнер В.C.", "Гайдар A.П.", "Белинский В.Г.", "Mережковский Д.C.", "Берггольц О.Д.", "Зощенко M.M.", "Пришвин M.M.", "Aндреев Л.H.", "Терехов A.H.", "Федоров A.И.", "Cавинков C.В.", "Глебов-Aзаров A.И.", "Глазычев В.П.", "Гиппиус З.H.", "Шервуд A.", "Жуковский В.A.", "Cкрябин A.H.", "Cтругацкие A. и Б.", "Гроссман В.C.", "Mартынов В.Г.", "Полевой Б.К.", "Aлексин A.Т.", "Пильняк Д.Б.", "Пастернак Б.Л.", "Терещенко И.A.", "Cимонов К.Т.", "Звегинцев В.Г.", "Cорокин В.Т.", "Тургенев И.C.", "Краснознаменская A.M.", "Ломоносов M.В.", "Фадеев A.A.", "Батюшков К.H.", "Mамин-Cибиряк Д.H.", "Толстой A.К.", "Тютчев Ф.И.", "Гончаров И.A.", "Куприн A.И.", "Грин A.C.", "Заболоцкий H.A.", "Aрхангельский И.Т.", "Тихонов H.C.", "Гудзон Г.", "Гайдар A.П.", "Дубовский В.H.", "Демченко A.A.", "Зайцев В.Г.", "Карпов В.П.", "Кочетов A.M.", "Левитан И.И.", "Mакаров В.В.", "Петров A.Т.", "Cавинков C.В.", "Троцкий Л.Д.", "Ремарк Э.M.", "Хессе Г.", "Hицше Ф.", "Камю A.", "Cартр Ж.-П.", "Cент-Экзюпери A. де", "Кингсли A.", "Голдинг У.", "Оруэлл Дж.", "Cтейнбек Дж.", "Хемингуэй Э.", "Фицджеральд Ф.C.", "Лондон Дж.", "Твен M.", "Диккенс Ч.", "Дойл A. Конан", "Остин Дж.", "Бронте Э.", "Достоевский Ф.", "Толстой Л.", "Дюма A.", "Верн Ж.", "Пушкин A.", "Лермонтов M.", "Толстой Л.", "Пастернак Б.", "Цветаева M.", "Пушкин A.", "Толстой Л.", "Достоевский Ф.", "Чехов A.", "Тургенев И.", "Гоголь H.", "Лермонтов M.", "Булгаков M.", "Cолженицын A.", "Гумилев H.", "Блок A.", "Mаяковский В.", "Есенин C.", "Aхматова A.", "Твардовский A.", "Бродский И.", "Замятин Е.", "Карамзин H.", "Бестужев-Mарлинский A.", "Фет A.", "Тютчев Ф.", "Hекрасов H.", "Бунин И.", "Шмелев И.", "Багрицкий Е.", "Горький M.", "Aйтматов Ч.", "Cапгир Д.", "Розанов В.", "Горький M.", "Паустовский К.", "Берггольц О.", "Бунин И.", "Mережковский Д.", "Cимонов К.", "Cолженицын A.", "Токарева И.", "Чернышевский H.", "Брикнер В.", "Гайдар A.", "Белинский В.", "Mережковский Д.", "Берггольц О.", "Зощенко M.", "Пришвин M.", "Aндреев Л.", "Терехов A.", "Федоров A.", "Cавинков C.", "Глебов-Aзаров A.", "Глазычев В.", "Гиппиус З.", "Шервуд A.", "Жуковский В.", "Cкрябин A.", "Cтругацкие A.", "Гроссман В.", "Mартынов В.", "Полевой Б.", "Aлексин A.", "Пильняк Д.", "Пастернак Б.", "Терещенко И.", "Cимонов К.", "Звегинцев В.", "Cорокин В.", "Тургенев И.", "Краснознаменская A.", "Ломоносов M.", "Фадеев A.", "Батюшков К.", "Mамин-Cибиряк Д.", "Толстой A.", "Тютчев Ф.", "Гончаров И.", "Куприн A.", "Грин A.", "Заболоцкий H.", "Aрхангельский И.", "Тихонов H.", "Гудзон Г.", "Гайдар A.", "Дубовский В.", "Демченко A.", "Зайцев В.", "Карпов В.", "Кочетов A.", "Левитан И.", "Mакаров В.", "Петров A.", "Cавинков C.", "Троцкий Л.", "Сидоров А.С.", "Иванов Б.П.", "Петров В.Г.", "Федоров Д.А.", "Николаев Е.И.", "Кузнецов Г.С.", "Александров Д.М.", "Борисов Е.П.", "Григорьев В.Ф.", "Михайлов И.В.", "Сергеев Л.А.", "Андреев Н.К.", "Васильев О.Е.", "Дмитриев П.С.", "Егоров Р.Н.", "Константинов С.В.", "Леонидов Т.М.", "Никитин У.А.", "Олегов Х.Ю.", "Павлов Ц.З.", "Романов Ш.А.", "Семенов Э.В.", "Тимофеев Ю.Д.", "Ульянов Ф.И.", "Харитонов Ч.П.", "Чернов Ш.М.", "Шестаков Ы.Е.", "Юрьев Я.Н.", "Яковлев А.Р.", "Антонов Б.С.", "Беляев В.А.", "Воронин Г.Д.", "Герасимов Д.Ж.", "Денисов Е.К.", "Ефимов Ж.Л.", "Жданов И.П.", "Зайцев К.Н.", "Игнатьев Л.М.", "Ковалев М.В.", "Лукин Н.П.", "Миронов О.Р.", "Наумов П.С.", "Осипов Р.Г.", "Петухов С.Х.", "Рябов Т.Ц.", "Соколов У.Ф.", "Трофимов Ф.Ч.", "Уваров Ш.Ш.", "Филатов Ы.Э.", "Хабаров Ю.Ю.", "Цветков Я.Я.", "Чернышев А.А.", "Шевцов Б.Б.", "Щербаков В.В.", "Эрдниев Г.Г.", "Юдин Д.Д.", "Яковлев Е.Е.", "Алексеев Ж.Ж.", "Белов И.И.", "Волков К.К.", "Громов Л.Л.", "Дмитриев М.М.", "Емельянов Н.Н.", "Жуков О.О.", "Зыков П.П.", "Исаев Р.Р.", "Козлов С.С.", "Лебедев Т.Т.", "Медведев У.У.", "Николаев Ф.Ф.", "Орлов Х.Х.", "Павлов Ц.Ц.", "Романов Ш.Ш.", "Сергеев Щ.Щ.", "Тимофеев Ы.Ы.", "Ульянов Ф.Ф.", "Федоров Х.Х.", "Харитонов Ч.Ч.", "Чернов Ш.Ш.", "Шестаков Ы.Ы.", "Юрьев Я.Я.", "Яковлев А.А.", "Антонов Б.Б.", "Беляев В.В.", "Воронин Г.Г.", "Герасимов Д.Д.", "Денисов Е.Е.", "Ефимов Ж.Ж.", "Жданов И.И.", "Зайцев К.К.", "Игнатьев Л.Л.", "Ковалев М.М.", "Лукин Н.Н.", "Миронов О.О.", "Наумов П.П.", "Осипов Р.Р.", "Петухов С.С.", "Рябов Т.Т.", "Соколов У.У.", "Трофимов Ф.Ф.", "Уваров Ш.Ш.", "Филатов Ы.Ы.", "Хабаров Ю.Ю.", "Цветков Я.Я.", "Чернышев А.А.", "Шевцов Б.Б.", "Щербаков В.В.", "Эрдниев Г.Г.", "Юдин Д.Д.", "Яковлев Е.Е.", "Алексеев Ж.Ж.", "Белов И.И.", "Волков К.К.", "Громов Л.Л.", "Дмитриев М.М.", "Емельянов Н.Н.", "Жуков О.О.", "Зыков П.П.", "Исаев Р.Р.", "Козлов С.С.", "Лебедев Т.Т.", "Медведев У.У.", "Николаев Ф.Ф.", "Орлов Х.Х.", "Павлов Ц.Ц.", "Романов Ш.Ш.", "Сергеев Щ.Щ.", "Тимофеев Ы.Ы.", "Ульянов Ф.Ф.", "Федоров Х.Х.", "Харитонов Ч.Ч.", "Чернов Ш.Ш.", "Шестаков Ы.Ы.", "Юрьев Я.Я.", "Яковлев А.А.", "Антонов Б.Б.", "Беляев В.В.", "Воронин Г.Г.", "Герасимов Д.Д.", "Денисов Е.Е.", "Ефимов Ж.Ж.", "Жданов И.И.", "Зайцев К.К.", "Игнатьев Л.Л.", "Ковалев М.М.", "Лукин Н.Н.", "Миронов О.О.", "Наумов П.П.", "Осипов Р.Р.", "Петухов С.С.", "Рябов Т.Т.", "Соколов У.У.", "Трофимов Ф.Ф.", "Уваров Ш.Ш.", "Филатов Ы.Ы.", "Хабаров Ю.Ю.", "Цветков Я.Я.", "Чернышев А.А.", "Шевцов Б.Б.", "Щербаков В.В.", "Эрдниев Г.Г.", "Юдин Д.Д.", "Яковлев Е.Е.", "Алексеев Ж.Ж.", "Белов И.И.", "Волков К.К.", "Громов Л.Л.", "Дмитриев М.М.", "Емельянов Н.Н.", "Жуков О.О.", "Зыков П.П.", "Исаев Р.Р.", "Козлов С.С.", "Лебедев Т.Т.", "Медведев У.У.", "Николаев Ф.Ф.", "Орлов Х.Х.", "Павлов Ц.Ц.", "Романов Ш.Ш.", "Сергеев Щ.Щ.", "Тимофеев Ы.Ы.", "Ульянов Ф.Ф.", "Федоров Х.Х.", "Харитонов Ч.Ч.", "Чернов Ш.Ш.", "Шестаков Ы.Ы.", "Юрьев Я.Я.", "Яковлев А.А.", "Антонов Б.Б.", "Беляев В.В.", "Воронин Г.Г.", "Герасимов Д.Д.", "Денисов Е.Е.", "Ефимов Ж.Ж.", "Жданов И.И.", "Зайцев К.К.", "Игнатьев Л.Л.", "Ковалев М.М.", "Лукин Н.Н.", "Миронов О.О.", "Наумов П.П.", "Осипов Р.Р.", "Петухов С.С.", "Рябов Т.Т.", "Соколов У.У.", "Трофимов Ф.Ф.", "Уваров Ш.Ш.", "Филатов Ы.Ы.", "Хабаров Ю.Ю.", "Цветков Я.Я.", "Чернышев А.А.", "Шевцов Б.Б.", "Щербаков В.В.", "Эрдниев Г.Г.", "Юдин Д.Д.", "Яковлев Е.Е.", "Алексеев Ж.Ж.", "Белов И.И.", "Волков К.К.", "Громов Л.Л.", "Дмитриев М.М.", "Емельянов Н.Н.", "Жуков О.О.", "Зыков П.П.", "Исаев Р.Р.", "Козлов С.С.", "Лебедев Т.Т.", "Медведев У.У.", "Николаев Ф.Ф.", "Орлов Х.Х.", "Павлов Ц.Ц.", "Романов Ш.Ш.", "Сергеев Щ.Щ.", "Тимофеев Ы.Ы.", "Ульянов Ф.Ф.", "Федоров Х.Х.", "Харитонов Ч.Ч.", "Чернов Ш.Ш.", "Шестаков Ы.Ы.", "Юрьев Я.Я.", "Яковлев А.А.", "Антонов Б.Б.", "Беляев В.В.", "Воронин Г.Г.", "Герасимов Д.Д.", "Денисов Е.Е.", "Ефимов Ж.Ж.", "Жданов И.И.", "Зайцев К.К.", "Игнатьев Л.Л.", "Ковалев М.М.", "Лукин Н.Н.", "Миронов О.О.", "Наумов П.П.", "Осипов Р.Р.", "Петухов С.С.", "Рябов Т.Т.", "Соколов У.У.", "Трофимов Ф.Ф.", "Уваров Ш.Ш.", "Филатов Ы.Ы.", "Хабаров Ю.Ю.", "Цветков Я.Я.", "Чернышев А.А.", "Шевцов Б.Б."
};

std::vector<std::string> BOOKS_LIST = {"Звезды вечности", "Сны забытых миров", "Легенды о времени", "Тайная жизнь магии", "Путешествие в прошлое", "Огонь и лед", "Магия звездных рассказов", "По ту сторону горизонта", "Дыхание неведомого", "Ключ от врат времени", "Тени невидимых звезд", "Волшебство мгновений", "Странствия по звездам", "Тайные страницы Вселенной", "Светлые тайны тьмы", "Загадки далеких галактик", "Песнь звездных волн", "Колыбельная для созвездий", "Звездный шепот во тьме", "Орбита мечты", "Призраки звездных путей", "Рисунки на облаках времени", "Туманные врата Вселенной", "Секреты звездных нитей", "Магия прошлого и будущего", "Сверкающие звезды в глазах", "Эхо звездных далей", "Галактические странники", "Звездопад в душе", "Летящие созвездия", "Волшебство космических лет", "Спрятанные светила", "Время магических зеркал", "Гиперпространственные загадки", "Исчезающие астероиды", "Звездные следы", "Тайна часового механизма", "Проклятие галактических тайн", "Сияние вечерних звезд", "Хроники звездного ковчега", "Астральные врата", "Подвиги космических магов", "Стражи звездных врат", "Созвездие детских грез", "Вершины небесных гор", "Путешествие в звездное сердце", "Вихрь галактических эпопей", "Орбитальные встречи", "Магический свет млечного пути", "Таинственные лунные следы", "Забытые звездные легенды", "Странные звездные письма", "Сказания о звездных мостах", "Астрономия волшебства", "Туманность снов", "Интергалактические истории", "Созвездие вдохновения", "Планетарные загадки", "Огонь звездной души", "Квантовая астрология", "Магия светил в темноте", "Лучи звездного сияния", "Гиперборейские звезды", "Мистические лучи галактик", "Секреты космической гармонии", "Путеводитель по звездам", "Восхождение звездных пиков", "Астрономические встречи", "Галактический мозаичный код", "Астральные приключения", "Сокровища космоса", "Вдохновение астрономии", "Проклятие черных дыр", "Астрономический феномен", "Волшебный космический камень", "Звездная алхимия", "Орбитальный взлет", "Время звездных путешествий", "Галактическая гармония", "Секреты межзвездного пространства", "Путешествие внутри светил", "Вихрь звездных снов", "Тайны космического магнетизма", "Магия галактических вихрей", "Звездные следопыты", "Магический космос", "Лунные откровения", "Звездные космогонии", "Астрономическая энциклопедия", "Семья звездных светил", "Иллюзии звездного пространства", "Заклинания космического света", "Квазары неведомого", "Врата космического времени", "Загадочные планеты", "Созвездия во тьме", "Галактическая фантазия", "Время астральных зеркал", "Космическая реальность", "Сверкающие моменты вечности", "Тайны гиперпространства", "Созвездие фантазий", "Гармония созвездий", "Путеводная звезда", "Исчезнувшие астероиды", "Летучие звезды", "Тайны космических волн", "Путеводная звезда", "Исчезнувшие астероиды", "Летучие звезды", "Тайны космических волн", "Орбитальные звездные истории", "Песнь магии в пространстве", "Светил в танце времени", "Звездные врата к другим мирам", "Астрономия в зеркале судьбы", "Галактический калейдоскоп", "Легенды о часах созвездий", "Вихрь космических загадок", "Ключ от гиперпространства", "Созвездия в зеркале снов", "Таинственные следы звезд", "Галактические картины времени", "Астральные хроники", "Звездные стражи", "Путешествие в черные дыры", "Тайна космических координат", "Огненные следы метеоритов", "Магическая пыль звезд", "Секреты космического света", "Легенды звездных рассветов", "Астральный оракул", "Сверкающие тайны космоса", "Астрономия магических далей", "Загадочные туманности", "Взлет в галактическое пространство", "Магия звездного путешествия", "Созвездие забытых миров", "Гиперпространственные откровения", "Путеводные светила", "Звездные эхо вечности", "Секреты космических структур", "Тайна звездного света", "Астрономический лабиринт", "Спрятанные звездные острова", "Летящие через времена", "Огненные волны космоса", "Магия галактических снов", "Встречи в иные миры", "Астральный ветер перемен", "Галактические откровения", "Песнь космических гармоний", "Тени звездных троп", "Астрономический феникс", "Магия космической симфонии", "Звездные тайны астрологии", "Путешествие в астральные глубины", "Созвездия в огне", "Исчезнувшие магические миры", "Взлет в астральное небо", "Орбитальные светила времени", "Галактическая мозаика звезд", "Тайна космических порталов", "Созвездие волшебных снов", "Лунные врата космоса", "Загадочные звездные коды", "Секреты гиперпространства", "Магические пути вечности", "Огненные стрелы космоса", "Вихрь астральных зеркал", "Тени звездных камней", "Астрономия волшебных историй", "Звездные странствия души", "Магические встречи в космосе", "Сверкающие астрономические миры", "Астральные врата времени", "Путеводные звезды галактик", "Легенды огненных космических следов", "Вихрь светил вечности", "Созвездия магических историй", "Тайны космического свитка", "Галактическая симфония времени", "Астрономия загадок космоса", "Звездные страницы волшебства", "Орбитальные загадки", "Секреты космической астрологии", "Магия светил в ночи", "Взлет в галактические тайны", "Созвездие магической весны", "Легенды орбитальных светил", "Астрономический код времени", "Звездные сказания в детстве", "Тайны космических переходов", "Огненные следы астральных странствий", "Магия космических путей", "Сокровища галактических рассветов", "Астральные волны света", "Звездная алхимия времени", "Гиперпространственные легенды", "Путешествие в глубины звезд", "Секреты магической космической пыли", "Туманные врата космоса", "Орбитальные загадки времени", "Галактическое великолепие", "Астрономия вечных снов", "Загадки космических узоров", "Созвездия светил в неведомом", "Легенды звездных древностей", "Астральные космические танцы", "Путешествие в магию звезд", "Сверкающие следы астральных странствий", "Магические огоньки в пространстве", "Вихрь космических тайн", "Тайна звездных путеводных камней", "Огненные звездные гармонии", "Светила в магии времени", "Гиперпространственные путеводные звезды", "Астрономия звездных светил", "Звездные легенды вечности", "Тайна космической ауры", "Орбитальные танцы в пространстве", "Галактические переходы", "Астральные стражи врот времени", "Загадочные звездные путеводные светила", "Сверкающие лунные космосы", "Астрономия в магическом зеркале", "Путешествие в огненные астральные миры", "Созвездие волшебных звезд", "Легенды огненного света", "Магический вихрь звездного времени", "Звездные странствия в астральные миры", "Таинственные огоньки в космосе", "Галактическая гармония света", "Астральные мечты о звездах", "Секреты звездных станций", "Путешествие в магические астральные сферы", "Тайна звездных лун", "Орбитальные звездные свитки", "Созвездия вековых снов", "Легенды огненных метеоров", "Астрономия космической фантазии", "Загадочные звездные туманности", "Сверкающие астрономические пути", "Астральные огоньки в небесах", "Гиперпространственные страницы созвездий", "Путешествие в световые галактические врата", "Сокровища огненных астральных далей", "Магия звездных хроник", "Звездные легенды в астральных мирах", "Тайна космической магнитной ауры", "Орбитальные огоньки света", "Галактические страницы вечности", "Астральные космические взлеты", "Загадочные лучи светил", "Сверкающие звездные зеркала", "Астрономия в магическом космосе", "Путешествие в астральные дали", "Тайны космических танцев", "Огненные странствия в неведомое", "Магические астрономические встречи", "Созвездия огненных драконов", "Легенды орбитальных путей", "Астральные следы светила", "Звездные магии во времени", "Таинственные врата светила", "Галактические огоньки времени", "Астрономия света в небесах", "Загадочные летучие огоньки", "Сверкающие космические сны", "Астральные вихри ветра", "Путешествие в астрономическую гармонию", "Сокровища звездных путей", "Магия космической пыли", "Звездные легенды астральных времен", "Тайна огненных светил", "Орбитальные звездные светила", "Галактические страницы снов", "Астральные странствия в галактическом пространстве", "Загадочные звездные переходы", "Сверкающие лучи вечности", "Астрономия огненного света", "Путешествие в астральные космические врата", "Тайны светила времени", "Огненные следы в астральных небесах", "Магическая гармония космических волн", "Звездные таинства в пространстве", "Секреты космических галактик", "Астральные странствия звезд", "Легенды огненного магнетизма", "Гиперпространственные огоньки времени", "Астрономический взлет в магию", "Загадочные звездные странники", "Сверкающие огненные пути", "Астральные ворота в космос", "Путешествие в светильные галактические врата", "Сокровища астральных светил", "Магия звездных вихрей", "Звездные легенды во времени", "Тайна огненных астральных следов", "Орбитальные страницы волшебства", "Галактические врата в астральные миры", "Астрономия света звезд", "Загадочные светила времени"
};

std::vector<std::string> GENRES_LIST = {"Фантастика", "Романтика", "Приключения", "Ужасы", "Научная фантастика", "Фэнтези", "Исторический роман", "Триллер", "Драма", "Комедия", "Биография", "Мистика", "Фольклор", "Экшн", "Криминал", "Детский", "Юмор", "Философия", "Психология", "Религия", "Политика", "Вестерн", "Спорт", "Научпоп", "Шпионский", "Документальный", "Технофанк", "Готика", "Экология", "Киберпанк", "Социальная драма", "Ретро", "Боевик", "Эротика", "Космическая опера", "Героическое фэнтези", "Антиутопия", "Постапокалипсис", "Супергеройский", "Тайм-тревел", "Хоррор", "Кулинария", "Фэнтези-роман", "Космический вестерн", "Интрига", "Документальная проза", "Психологический триллер", "Космическая фантастика", "Религиозный триллер", "Бизнес", "Экономика", "Научно-популярная проза", "Комикс", "Исторический триллер", "Магический реализм", "Киберпанк-опера", "Научная фантастика для подростков", "Ретрофутуризм", "Эпическое фэнтези", "Средневековье", "Спортивный роман", "Технотриллер", "Мистический детектив", "Альтернативная история", "Байопик", "Космический детектив", "Спецагент", "Историческая фантастика", "Теологический триллер", "Биографический роман", "Юмористический детектив", "Детская фантастика", "Спортивная драма", "Фэнтези для подростков", "Метафизический роман", "Кинематограф", "Военная драма", "Гиперреализм", "Музыка", "Автобиография", "Искусство", "Социальная комедия", "Технотриллер для подростков", "Романтическая комедия", "Эзотерика", "Постапокалиптический триллер", "Магический триллер", "Сверхъестественное", "Спортивная фантастика", "Кинематографическая проза", "Религиозная фантастика", "Автограф", "Интерактивная проза", 
"Генетический триллер", "Технологическая фантастика", "Авантюрный роман", "Сказка", "Реализм", "Экологический триллер", "Историческое приключение", "Ботанический детектив", "Трансформационный роман", "Киберпанк-фэнтези", "Психофантастика", "Археологический триллер", "Семейная драма", "Детектив-головоломка", "Астрономический роман", "Гуманистический триллер", "Экспериментальная проза", "Юмористическая фантастика", "Театральная драма", "Религиозная драма", "Буддийская проза", "Философский детектив", "Ретро-детектив", "Бизнес-детектив", "Метафорическая проза", "Постапокалиптическая фантастика", "Кулинарный детектив", "Сверхъестественный детектив", "Готический детектив", "Энциклопедический роман", "Семейный детектив", "Тайный агент", "Мифопоэтическая проза", "Религиозная поэзия", "Технологический детектив", "Современная сказка", "Магическая комедия", "Эпистолярная проза", "Электронная литература", "Этнографическая проза", "Спортивный триллер", "Современная драма", "Футуристическая фантастика", "Магический триллер для подростков", "Эссе", "Социальная сага", "Эпистолярный роман", "Философская фантастика", "Фэнтези-триллер", "Сатирический детектив"
};

std::vector<std::string> SUBSCRIBERS_LIST = {"Артемов А.В.", "Смирнов С.А.", "Иванова Е.И.", "Петров М.Д.", "Кузнецова О.Н.", "Лебедев Г.С.", "Соколов К.А.", "Морозова Л.М.", "Новиков М.П.", "Козлова К.В.", "Орлова Е.С.", "Беляев И.А.", "Андреева Д.В.", "Макарова Н.И.", "Елисеев П.О.", "Николаев А.Ф.", "Васнецова С.В.", "Герасимов Д.Г.", "Попов А.Ю.", "Селиванова Е.Р.", "Титов А.Е.", "Комарова А.К.", "Соловьев М.А.", "Зайцева Л.В.", "Сорокин П.С.", "Семенова Н.Н.", "Романов С.Ю.", "Краснова А.Р.", "Петухова О.Д.", "Куликов И.В.", "Игнатьева С.Г.", "Лазарева И.Ю.", "Кудряшова А.В.", "Жукова Е.П.", "Баранов Г.А.", "Мартынова А.В.", "Беляков Д.С.", "Григорьева Н.С.", "Горбунова И.А.", "Богданова Н.А.", "Осипов С.В.", "Селезнев А.С.", "Панова Е.И.", "Михайлов А.М.", "Фролова С.Д.", "Логинова Н.А.", "Захаров А.В.", "Ларин С.А.", "Ефимов Д.С.", "Семенов С.П.", "Лихачева А.Е.", "Зуев В.И.", "Макеева Е.Л.", "Гусев М.А.", "Ермакова О.Г.", "Грачев Д.Н.", "Константинов Д.А.", "Щербакова А.Ф.", "Горшков С.С.", "Болдырева Л.М.", "Ильина М.П.", "Галкина К.В.", "Лапина Е.С.", "Артемьев И.А.", "Поляков С.В.", "Аксенова А.Ю.", "Князев Д.Г.", "Антонов Д.В.", "Крылова Н.И.", "Носков И.Ф.", "Богачев С.В.", "Лебедьева А.К.", "Власова Л.А.", "Сухова М.С.", "Савельев П.С.", "Горбачева А.Н.", "Лаптев А.А.", "Федотова И.В.", "Трофимов И.Д.", "Афанасьева О.Г.", "Литвинов А.И.", "Игнатова Н.А.", "Кудрявцева Л.В.", "Назаров Д.С.", "Сорокина Е.Р.", "Степанов М.Е.", "Бирюков П.А.", "Богданов С.А.", "Суслова Н.В.", "Карпова С.В.", "Архипов И.Г.", "Колесникова А.П.", "Исаева И.Д.", "Журавлев Д.А.", "Мамонтова К.С.", "Муравьева А.Н.", "Егоров И.Л.", "Троицкий А.С.", "Субботин С.А.", "Лихачев И.В.", "Сидорова А.Е.", "Комиссаров А.В.", "Антонов Ю.Д.", "Тимофеева Е.Л.", "Бессонов А.А.", "Потапова Л.М.", "Баранова К.В.", "Голубева А.С.", "Макеев М.П.", "Семенов И.О.", "Павлов Д.А.", "Кудряшов С.И.", "Ткачева Е.Н.", "Рыбаков С.М.", "Денисова А.М.", "Мельникова И.А.", "Шилов А.С.", "Гордеева Е.В.", "Сафонов И.Л.", "Лисина А.П.", "Симонова М.Д.", "Артемьева К.Л.", "Беляев Д.Г.", "Щербаков Д.С.", "Головина И.А.", "Сазонова Е.В.", "Сергеева С.П.", "Кузьмина М.С.", "Иванов Л.В.", "Богомолова А.Н.", "Шестаков И.В.", "Фомина А.И.", "Антропов С.А.", "Медведев И.М.", "Дмитриева Л.Д.", "Гусев С.П.", "Ильин А.Н.", "Федотов М.Г.", "Киселева Е.В.", "Тихонов М.А.", "Поляков С.В.", "Беляков И.Д.", "Кузьмин С.А.", "Жукова Е.Н.", "Комиссарова И.И.", "Горбунов Д.В.", "Попов И.Л.", "Александров А.Н.", "Тихонов И.В.", "Журавлева М.М.", "Сорокина А.Г.", "Логинов С.П.", "Семенова Е.Г.", "Бирюков В.С.", "Соколов Д.В.", "Лебедев Л.И.", "Григорьев Д.А.", "Комаров С.Л.", "Михайлов Д.Д.", "Петрова М.Г.", "Миронов И.С.", "Троицкая И.А.", "Голубева А.И.", "Андреев А.Н.", "Кузнецов Д.А.", "Петров С.Д.", "Григорьева С.Л.", "Новиков А.С.", "Орлов С.И.", "Смирнов Д.В.", "Шилова К.В.", "Семенов И.Г.", "Мартынова К.А.", "Галкин В.И.", "Сафонов А.Д.", "Лаптев И.Н.", "Быков И.С.", "Антонов И.В.", "Козлов Д.Д.", "Селиванов Д.А.", "Жуков В.М.", "Попов И.Д.", "Гусев И.П.", "Соколов С.А.", "Иванова Е.И.", "Петров М.Д.", "Кузнецова О.Н.", "Лебедев Г.С.", "Соколов К.А.", "Морозова Л.М.", "Новиков М.П.", "Козлова К.В.", "Орлова Е.С.", "Беляев И.А.", "Андреева Д.В.", "Макарова Н.И.", "Елисеев П.О.", "Николаев А.Ф.", "Васнецова С.В.", "Герасимов Д.Г.", "Попов А.Ю.", "Селиванова Е.Р.", "Титов А.Е.", "Комарова А.К.", "Соловьев М.А.", "Зайцева Л.В.", "Сорокин П.С.", "Семенова Н.Н.", "Романов С.Ю.", "Краснова А.Р.", "Петухова О.Д.", "Куликов И.В.", "Игнатева С.Г.", "Лазарева И.Ю.", "Кудряшова А.В.", "Жукова Е.П.", "Баранов Г.А.", "Мартынова А.В.", "Беляков Д.С.", "Григорьева Н.С.", "Горбунова И.А.", "Богданова Н.А.", "Осипов С.В.", "Селезнев А.С.", "Панова Е.И.", "Михайлов А.М.", "Фролова С.Д.", "Логинова Н.А.", "Захаров А.В.", "Ларин С.А.", "Ефимов Д.С.", "Семенов С.П.", "Лихачева А.Е.", "Зуев В.И.", "Макеева Е.Л.", "Гусев М.А.", "Ермакова О.Г.", "Грачев Д.Н.", "Константинов Д.А.", "Щербакова А.Ф.", "Горшков С.С.", "Болдырева Л.М.", "Ильина М.П.", "Галкина К.В.", "Лапина Е.С.", "Артемьев И.А.", "Поляков С.В.", "Аксенова А.Ю.", "Князев Д.Г.", "Антонов Д.В.", "Крылова Н.И.", "Носков И.Ф.", "Богачев С.В.", "Лебедьева А.К.", "Власова Л.А.", "Сухова М.С.", "Савельев П.С.", "Горбачева А.Н.", "Лаптев А.А.", "Федотова И.В.", "Трофимов И.Д.", "Афанасьева О.Г.", "Литвинов А.И.", "Игнатова Н.А.", "Федоров Д.А.", "Харитонова А.Е.", "Цветков Н.И.", "Чернов И.Л.", "Шарапов Д.П.", "Щербаков С.А.", "Юдин И.Г.", "Яковлева М.В.", "Андреев И.А.", "Богданова О.Г.", "Васнецова А.А.", "Герасимов С.М.", "Давыдова И.Д.", "Ефимова Е.П.", "Журавлев Д.М.", "Зимина О.Н.", "Игнатова Е.С.", "Козлова А.Л.", "Лебедева А.Д.", "Максимов Д.К.", "Нестерова К.А.", "Овчинников И.А.", "Попова И.С.", "Руднева А.Н.", "Савельева П.С.", "Тимофеева М.В.", "Успенский И.И.", "Федосеев Д.А.", "Хрусталева Е.А.", "Цветкова С.Л.", "Чернов Д.И.", "Широкова А.П.", "Щеглова И.Е.", "Юрьев И.А.", "Яковлев П.М.", "Антонов Д.С.", "Белякова В.О.", "Воробьева М.С.", "Горбунов Д.А.", "Дубровская Е.И.", "Ефремова М.В.", "Жуков Д.В.", "Зайцева Т.А.", "Ильина А.К.", "Кузьмина Т.М.", "Леонов И.Н.", "Макарова А.Г.", "Никитина С.П.", "Осипова А.А.", "Петрова Н.М.", "Романов Д.П.", "Смирнов Д.В.", "Тимошенко С.В.", "Ульянов В.В.", "Федорова П.М.", "Харитонов С.И.", "Цветков И.Е.", "Чернов И.А.", "Шарапов И.Г.", "Щербакова А.П.", "Юдин С.И.", "Яковлева Н.Л.", "Андреева В.Д.", "Богданов И.В.", "Васнецов Д.А.", "Герасимова С.П.", "Давыдова Н.И.", "Ефимова Т.Д.", "Журавлева Е.В.", "Зимин С.К.", "Игнатова И.Л.", "Козлова Е.П.", "Лебедева С.А.", "Максимова А.М.", "Нестерова М.С.", "Овчинников И.Н.", "Попова О.И.", "Руднева М.К.", "Савельева А.И.", "Тимофеева А.В.", "Успенский А.В.", "Федосеева К.В.", "Хрусталева С.П.", "Цветкова О.А.", "Чернова В.Л.", "Широкова С.А.", "Щеглова Д.А.", "Юрьева Н.А.", "Яковлева А.В.", "Антонова С.Г.", "Белякова Т.М.", "Воробьева П.А.", "Горбунова А.П.", "Дубровский М.В.", "Ефремова С.А.", "Жукова А.К.", "Зайцева И.А.", "Ильина И.Л.", "Кузьмина Е.П.", "Леонова О.М.", "Макарова Н.В.", "Никитина Е.И.", "Осипова Е.П.", "Петрова Т.А.", "Романова И.В.", "Смирнова А.К.", "Тимошенко О.И.", "Ульянова К.Д.", "Федорова С.М.", "Харитонова И.Е.", "Цветкова М.В.", "Чернова А.К.", "Шарапова Н.С.", "Щербакова Е.А.", "Юдин С.А.", "Яковлева П.А.", "Андреев А.С.", "Богданова С.В.", "Васнецова Е.И.", "Герасимова О.М.", "Давыдова А.А.", "Ефимов Д.С.", "Журавлев Д.И.", "Зимин А.П.", "Игнатова Е.М.", "Козлова С.А.", "Лебедева К.П.", "Максимова Т.В.", "Нестерова В.С.", "Овчинникова А.И.", "Попова А.М.", "Руднева С.В.", "Савельева Е.Д.", "Тимофеева И.М.", "Успенский Д.А.", "Федосеева С.А.", "Хрусталева Т.В.", "Цветкова Т.А.", "Чернова И.С.", "Широкова О.В.", "Щеглова В.М.", "Юрьева Т.К.", "Яковлева С.С.", "Антонов Д.А.", "Белякова Е.А.", "Воробьева К.С.", "Горбунов А.В.", "Дубровская А.П.", "Ефремова Н.Д.", "Жукова Е.М.", "Зайцева М.В.", "Ильина Е.А.", "Кузьмина С.С.", "Леонова А.В.", "Макарова С.С.", "Никитина В.И.", "Осипова В.А.", "Петрова И.И.", "Романова Н.К.", "Смирнова Д.М.", "Тимошенко А.И.", "Ульянова С.В.", "Федорова А.А.", "Харитонова Т.С.", "Цветкова О.В.", "Чернова К.М.", "Шарапова Е.Г.", "Щербакова К.В.", "Юдин С.И.", "Яковлева М.П.", "Андреева В.И.", "Богданова С.А.", "Васнецова Е.А.", "Герасимова О.П.", "Давыдова С.И.", "Ефимов С.С.", "Журавлева Т.Н.", "Зимина С.В.", "Игнатова А.Д.", "Козлова И.Н.", "Лебедева Т.Д.", "Максимова И.А.", "Нестерова А.П.", "Овчинникова С.В.", "Попова Д.И.", "Руднева Т.А.", "Савельева П.И.", "Тимофеева С.А.", "Успенский С.С.", "Федосеева Д.С.", "Хрусталева И.В.", "Цветкова А.И.", "Чернова В.В.", "Широкова Е.А.", "Щеглова Д.Д.", "Юрьева С.Л.", "Яковлева И.И."
};

std::vector<int> randomSample(const std::vector<int>& population, int k) {
    std::vector<int> result;
    
    if (k > population.size()) {
        std::cerr << "Error: Sample size k is larger than the population size\n";
        return result;
    }
    
    std::vector<int> indices(population.size());
    std::iota(indices.begin(), indices.end(), 0);
    
    std::random_device rd;
    std::mt19937 gen(rd());
    
    for (int i = 0; i < k; ++i) {
        std::uniform_int_distribution<> dist(i, population.size() - 1);
        int randomIndex = dist(gen);
        
        std::swap(indices[i], indices[randomIndex]);
        result.push_back(population[indices[i]]);
    }
    
    return result;
}

std::string formatStr(std::string str) {
    return str + std::string(255 - str.size(), ' ');
}

int authorInsertion(int number) {

    FILE *f; 
    f = fopen("authors.bin", "wb");

    fwrite(&number, sizeof(int), 1, f);
    int countColumns = 2;
    fwrite(&countColumns, sizeof(int), 1, f);

    std::string column1 = formatStr(std::string("id"));;
    std::string column2 = formatStr(std::string("a_name"));
    std::string intType = formatStr(std::string("int"));
    std::string stringType = formatStr(std::string("char(256)"));

    fwrite((char*) column1.c_str(), column1.length() + 1, 1, f);
    fwrite((char*) column2.c_str(), column2.length() + 1, 1, f);
    fwrite((char*) intType.c_str(), intType.length() + 1, 1, f);
    fwrite((char*) stringType.c_str(), stringType.length() + 1, 1, f);

    int id_seq = 1;
    int n = AUTHOR_LIST.size();
    for (int i = 0; i < number; i++) {
        fwrite(&id_seq, sizeof(int), 1, f);
        id_seq++;

        std::string name = formatStr(AUTHOR_LIST[rand() % n]);
        fwrite((char*) name.c_str(), name.length() + 1, 1, f);
    }

    fclose(f); 
    std::cout << "Generate " << number << " records about the authors" << std::endl;
    
    return 0;
}

int booksInsertion(int number) {
    FILE *f; 
    f = fopen("books.bin", "wb");

    fwrite(&number, sizeof(int), 1, f);
    int countColumns = 4;
    fwrite(&countColumns, sizeof(int), 1, f);

    std::string column1 = formatStr(std::string("id"));;
    std::string column2 = formatStr(std::string("b_name"));
    std::string column3 = formatStr(std::string("b_year"));
    std::string column4 = formatStr(std::string("b_quantity"));
    std::string intType = formatStr(std::string("int"));
    std::string stringType = formatStr(std::string("char(256)"));

    fwrite((char*) column1.c_str(), column1.length() + 1, 1, f);
    fwrite((char*) column2.c_str(), column2.length() + 1, 1, f);
    fwrite((char*) column3.c_str(), column3.length() + 1, 1, f);
    fwrite((char*) column4.c_str(), column4.length() + 1, 1, f);
    fwrite((char*) intType.c_str(), intType.length() + 1, 1, f);
    fwrite((char*) stringType.c_str(), stringType.length() + 1, 1, f);
    fwrite((char*) intType.c_str(), intType.length() + 1, 1, f);
    fwrite((char*) intType.c_str(), intType.length() + 1, 1, f);

    int id_seq = 1;
    int n = BOOKS_LIST.size();
    for (int i = 0; i < number; i++) {
        fwrite(&id_seq, sizeof(int), 1, f);
        id_seq++;

        std::string name = formatStr(BOOKS_LIST[rand() % n]);
        fwrite((char*) name.c_str(), name.length() + 1, 1, f);

        int year = rand() % 400 + 1600;
        int quantity = rand() % 20;
        fwrite(&year, sizeof(int), 1, f);
        fwrite(&quantity, sizeof(int), 1, f);
    }

    fclose(f); 
    std::cout << "Generate " << number << " records about the books" << std::endl;
    
    return 0;
}

int insertionBooksAuthor() {

    int authorsCount = 0, booksCount = 0;
    FILE *f; 
    f = fopen("authors.bin", "rb");
    fread(&authorsCount, sizeof(int), 1, f);
    fclose(f); 

    f = fopen("books.bin", "rb");    
    fread(&booksCount, sizeof(int), 1, f);
    fclose(f); 

    std::vector<int> authorsId = {};
    for (int i = 1; i <= authorsCount; i++) {
        authorsId.push_back(i);
    }

    std::vector<int> ramdomDig = {};
    int count = 0;
    for (int i = 1; i <= booksCount; i++) {
        int k = 1 + rand() % 3;
        count += k; 
        ramdomDig.push_back(k);
    }

    f = fopen("books_authors.bin", "wb");

    fwrite(&count, sizeof(int), 1, f);
    int countColumns = 2;
    fwrite(&countColumns, sizeof(int), 1, f);

    std::string column1 = formatStr(std::string("b_id"));;
    std::string column2 = formatStr(std::string("a_id"));
    std::string intType = formatStr(std::string("int"));

    fwrite((char*) column1.c_str(), column1.length() + 1, 1, f);
    fwrite((char*) column2.c_str(), column2.length() + 1, 1, f);
    fwrite((char*) intType.c_str(), intType.length() + 1, 1, f);
    fwrite((char*) intType.c_str(), intType.length() + 1, 1, f);

    for (int i = 1; i <= booksCount; i++) {
        int k = ramdomDig[i - 1];
        std::vector<int> buf = randomSample(authorsId, k);
        for (int j = 0; j < k; j++) {
            fwrite(&i, sizeof(int), 1, f);
            fwrite(&buf[j], sizeof(int), 1, f);
        }
    }

    fclose(f); 
    std::cout << "Generate " << count << " records about the books-authors" << std::endl;
    
    return 0;
}

int main() {
    srand(time(NULL));
    authorInsertion(10);
    booksInsertion(20);
    insertionBooksAuthor();
    return 0;
}