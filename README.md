
## Opis narzędzia

Jest to narzędzie do optymalizacji przydziału sędziów piłkarskich na określone mecze. Każdy sędzia ma określone miejsce zamieszkania
i każdy mecz ma określoną lokalizację. Algorytm zachłanny przydziela mecze tak, aby suma odległości
które sędziowie muszą przejechać aby dostać się na mecz była minimalna. Program zakłada
że do każdego meczu przydzieleni mają być dokładnie trzej sędziowie i każdy sędzia może być przydzielony dokładnie raz.

## Użyte zewnętrzne biblioteki

- `<nlohmann/json.hpp>` - biblioteka do obsługi plików JSON w C++.
- `<SFML/Graphics.hpp>` - (Simple and Fast Multimedia Library) - biblioteka do tworzenia grafiki i aplikacji multimedialnych w C++.

## Struktura wejściowych plików JSON
Plik `referees.json` to powinna być lista następujących obiektów reprezentujących sędziego:
```json
{ "name":"Adam",
  "surname":"Nowak",
  "location":{"x":534,"y":123},
  "skills":7
}
```
Plik `matches.json` to powinna być lista następujących obiektów z informacjami o meczu:
```json
{
  "date": "2025-06-02",
  "time": "20:30",
  "location": { "x": 430, "y": 720 },
  "home_team": "Real Madrid",
  "away_team": "Barcelona"
}
```
## Użycie
Najpierw pobierz projekt lokalnie:
```bash
git clone https://github.com/martowicz/referee-assigner.git
```

Przejdź do folderu z plikiem wykonywalnym 
```bash
cd cmake-build-debug
```
Wykonaj następującą komendę:
```bash
./RefsAndMatches <referees_filepath> <matches_filepath>
```
Po wykonaniu wyświetli się okienko z wizualizacją przydziału sędziów, a do tego przydział
zostanie zapisany do pliku `output.csv` w obecnym folderze