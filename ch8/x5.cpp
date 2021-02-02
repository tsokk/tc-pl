#include <iostream>
#include <locale>

using namespace std;

// I started with an enum class and defined overloads for
// operators >> and << for that class. Also, operators ++
// and -- were easy to define.
//
// The second part of this exercise led me to read chapter
// 39 and I changed the implementation to reflect the example
// there, to get the localization. Now, however, I've tried
// to define ++ and -- operations for the below version, but
// have not succeeded. I need to learn more to do that.

enum Season { spring, summer, fall, winter };

class Season_io : public locale::facet {
public:
  Season_io(size_t i = 0) : locale::facet{i} {}
  ~Season_io() {}

  virtual const string &to_str(Season x) const = 0;
  virtual bool from_str(const string &s, Season &x) const = 0;

  static locale::id id;
};

locale::id Season_io::id;

istream &operator>>(istream &is, Season &x) {
  const locale &loc{is.getloc()};

  if (has_facet<Season_io>(loc)) {
    const Season_io &f{use_facet<Season_io>(loc)};

    string buf;
    if (!(is >> buf && f.from_str(buf, x))) {
      is.setstate(ios_base::failbit);
    }
    return is;
  }

  int i;
  is >> i;
  x = static_cast<Season>(i);
  return is;
}

ostream &operator<<(ostream &os, Season &x) {
  locale loc{os.getloc()};

  if (has_facet<Season_io>(loc)) {
    return os << use_facet<Season_io>(loc).to_str(x);
  }
  return os << static_cast<int>(x);
}

class FI_season_io : public Season_io {
  static const string seasons[];

public:
  const string &to_str(Season) const;
  bool from_str(const string &, Season &) const;
};

const string FI_season_io::seasons[] = {"talvi", "kevät", "kesä", "syksy"};

const string &FI_season_io::to_str(Season x) const {
  if (x < Season::spring || Season::winter < x) {
    static const string ss = "no-such-season";
    return ss;
  }
  return seasons[x];
}

bool FI_season_io::from_str(const string &s, Season &x) const {
  const string *p = find(begin(seasons), end(seasons), s);
  if (p == end(seasons)) {
    return false;
  }

  x = Season(p - begin(seasons));
  return true;
}

int main() {
  Season x;
  cin >> x;
  cout << x << '\n';

  locale loc(locale(), new FI_season_io{});
  cout.imbue(loc);
  cin.imbue(loc);

  cin >> x;
  cout << x << '\n';
}
