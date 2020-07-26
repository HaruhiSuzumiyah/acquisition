#pragma once

#include <QRectF>
#include <QColor>
#include "rapidjson/document.h"

#include "itemconstants.h"
#include "rapidjson_util.h"
#include "QsLog.h"

enum class ItemLocationType {
    STASH,
    CHARACTER
};

class ItemLocation {
public:
    ItemLocation();
    explicit ItemLocation(const rapidjson::Value &root);
    ItemLocation(int tab_id, std::string name, ItemLocationType = ItemLocationType::STASH);
    void ToItemJson(rapidjson::Value *root, rapidjson_allocator &alloc);
    void FromItemJson(const rapidjson::Value &root);
    std::string GetHeader() const;
    QRectF GetRect() const;
    std::string GetForumCode(const std::string &league) const;
    std::string GetUniqueHash() const;
    bool IsValid() const;
    bool operator<(const ItemLocation &other) const;
    void set_type(const ItemLocationType type) { type_ = type; }
    ItemLocationType get_type() const { return type_; }
    void set_character(const std::string &character) { character_ = character; }
    void set_tab_id(int tab_id) { tab_id_ = tab_id; }
    void set_tab_label(const std::string &tab_label) { tab_label_ = tab_label; }
    std::string get_tab_label() const { return tab_label_; }
    bool socketed() const { return socketed_; }
    void set_socketed(bool socketed) { socketed_ = socketed; }
    int get_tab_id() const { return tab_id_; }
    int getR() const {return r_;}
    int getG() const {return g_;}
    int getB() const {return b_;}
    void SetBackgroundColor(const int r, const int g, const int b);
private:
    int x_, y_, w_, h_;
    int r_, g_, b_;
    bool socketed_;
    ItemLocationType type_;
    int tab_id_{0};
    std::string tab_label_;
    std::string character_;
    std::string inventory_id_;
};
