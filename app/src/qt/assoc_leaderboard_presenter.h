/*
 assoc_leaderboard_presenter.h     MindForger thinking notebook

 Copyright (C) 2016-2018 Martin Dvorak <martin.dvorak@mindforger.com>

 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 2
 of the License, or (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program. If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef M8RUI_ASSOC_LEADERBOARD_PRESENTER_H
#define M8RUI_ASSOC_LEADERBOARD_PRESENTER_H

#include <vector>

#include "assoc_leaderboard_view.h"
#include "assoc_leaderboard_model.h"
#include "orloj_presenter.h"
#include "html_delegate.h"

#include <QtWidgets>

#include "../../lib/src/model/note.h"

namespace m8r {

class AssocLeaderboardPresenter : public QObject
{
    Q_OBJECT

private:
    AssocLeaderboardView* view;
    AssocLeaderboardModel* model;

    OrlojPresenter* orloj;

public:
    explicit AssocLeaderboardPresenter(AssocLeaderboardView* view, OrlojPresenter* orloj);
    AssocLeaderboardPresenter(const AssocLeaderboardPresenter&) = delete;
    AssocLeaderboardPresenter(const AssocLeaderboardPresenter&&) = delete;
    AssocLeaderboardPresenter &operator=(const AssocLeaderboardPresenter&) = delete;
    AssocLeaderboardPresenter &operator=(const AssocLeaderboardPresenter&&) = delete;
    ~AssocLeaderboardPresenter();

    void refresh(std::vector<std::pair<Note*,float>>& assocLeaderboard);
    AssocLeaderboardView* getView() const { return view; }

public slots:
    void slotShowNote(const QItemSelection& selected, const QItemSelection& deselected);
};

}
#endif // M8RUI_ASSOC_LEADERBOARD_PRESENTER_H
